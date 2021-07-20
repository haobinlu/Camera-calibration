#include "pic_collect.h"
#include "ui_pic_collect.h"
#include <QPixmap>

using namespace std;
using namespace cv;

pic_collect::pic_collect(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	QString str = QString("main thread id:%3").arg((int)QThread::currentThreadId());
	qDebug() << str;

	label_RGB_height = ui.label_RGB_1->height();
	label_RGB_width = ui.label_RGB_1->width();

	utils->init_csv();

	//注册用户
	connect(ui.pushButton_regist, SIGNAL(clicked()), this, SLOT(regist()));
	//删除用户
	connect(ui.pushButton_del, SIGNAL(clicked()), this, SLOT(del_user()));

	//处理图像的负责通信的thread
	thread_process_1 = new mainthread_process(camera_RBGD_1_idx);
	connect(thread_process_1, &mainthread_process::processed_QImage, this, &pic_collect::show_frameset_1);
	connect(thread_process_1, &mainthread_process::recordProgress, this, &pic_collect::update_recordProgress);
	connect(thread_process_1, &mainthread_process::signal_check_compelet, this, &pic_collect::check_compelet);
	thread_process_1->start();

	thread_process_2 = new thread_process(camera_RBGD_2_idx);
	connect(thread_process_2, &thread_process::processed_QImage, this, &pic_collect::show_frameset_2);
	thread_process_2->start();

	qRegisterMetaType< Mat >("Mat&");
	qRegisterMetaType< Mat >("Mat");
	qRegisterMetaType< frameset >("frameset");
	//realsense  RGBD_1
	thread_cam_1 = new thread_cam(camera_RBGD_1_idx);
	connect(thread_cam_1,&thread_cam::signal_frameset, this, &pic_collect::pass_frameset_1);
	

	//connect(thread_cam_1, SIGNAL(signal_frameset(rs2::frameset)), this, SLOT(show_frameset_1(rs2::frameset)));
	thread_cam_1->start();

	//realsense RGBD_2
	thread_cam_2 = new thread_cam(camera_RBGD_2_idx);
	//connect(thread_cam_2, SIGNAL(signal_frameset(rs2::frameset)), this, SLOT(show_frameset_2(rs2::frameset)));
	connect(thread_cam_2, &thread_cam::signal_frameset, this, &pic_collect::pass_frameset_2);
	
	thread_cam_2->start();

}

void pic_collect::regist() {
	ui.label_status->clear();
	current_NO = ui.lineEdit_NO->text();
	//current_NO = QString("%1").arg(ui.lineEdit_NO->text().toInt(), 5, 10, QChar('0'));
	current_ID = ui.lineEdit_ID->text();
	current_sex = ui.comboBox_sex->currentText();

	if (current_NO == "" || current_ID == "" || current_sex == "") {
		QMessageBox::warning(this, "Warning", QString::fromLocal8Bit("当前用户信息不全，请重新填写"));
		return;
	}
	
	if (std::find(user_sample_num_ls.begin(), user_sample_num_ls.end(), current_NO.toStdString()) != user_sample_num_ls.end()) {
		auto reply = QMessageBox::question(this, "Question", QString::fromLocal8Bit("当前用户已注册完成, 如需重新注册请按确定继续"), QMessageBox::Ok | QMessageBox::Close, QMessageBox::Close);
		if (reply != QMessageBox::Ok) {
			return;
		}
	}
	qDebug() << "regist" << endl;
	thread_process_1->issave = true;
	thread_process_2->issave = true;
}

void pic_collect::del_user() {
	current_NO = ui.lineEdit_NO->text();
	if (current_NO == "") {
		QMessageBox::warning(this, "Warning", QString::fromLocal8Bit("请选择需要删除的用户"));
		return;
	}
	else
	{
		auto pos = std::find(user_sample_num_ls.begin(), user_sample_num_ls.end(), current_NO.toStdString());
		if (pos != user_sample_num_ls.end()) {
			ui.lineEdit_NO->setText("");
			ui.lineEdit_ID->setText("");
			ui.label_status->clear();
			user_sample_num_ls.erase(pos);
			//删除该用户的整个文件夹
			QString dir_path = root_path + "/sample_" + current_NO + "/";
			QDir dir(dir_path);
			dir.removeRecursively();
			ifstream inFile(information_csv_path, ios::in);
			string lineStr;
			vector<string> remain;
			while (getline(inFile, lineStr)) {
				stringstream ss(lineStr);  //来自sstream
				string str;

				while (getline(ss, str, ',')) {
					if (str != current_NO.toStdString()) {
						remain.push_back(lineStr);

					}
					break;
				}
			}
			ofstream file;
			file.open(information_csv_path, std::ios::out);
			for (int i = 0; i < remain.size(); i++) {
				file << remain[i] << "\n";
			}
			file.close();
			current_NO = "";
			current_ID = "";
			current_sex = "";
		}
		else
		{
			QMessageBox::warning(this, "Warning", QString::fromLocal8Bit("该用户未注册，请检查信息是否正确"));
		}
	}
}

void pic_collect::show_frameset_1(QImage data1, QImage data2) {
	ui.label_RGB_1->setPixmap(QPixmap::fromImage(data1));
	ui.label_RGB_7->setPixmap(QPixmap::fromImage(data2));
}


void pic_collect::show_frameset_2(QImage data1, QImage data2) {
	ui.label_RGB_2->setPixmap(QPixmap::fromImage(data1));
	ui.label_RGB_8->setPixmap(QPixmap::fromImage(data2));
}

void pic_collect::pass_frameset_1(frameset data) {
	thread_process_1->data = data;
	thread_process_1->isRunning = true;
}

void pic_collect::pass_frameset_2(frameset data) {
	thread_process_2->data = data;
	thread_process_2->isRunning = true;
}

void pic_collect::update_recordProgress(int value) {
	ui.progressBar->setValue(value);
}

void pic_collect::check_compelet() {
	if (thread_process_1->compelet && thread_process_2->compelet) {
		
		if (FrameNum_cam1 == FrameNum_cam2) {
			ui.label_status->setStyleSheet("color:green");
			ui.label_status->setText(QString::fromLocal8Bit("相片采集完成,严格对齐"));
		}
		else
		{
			ui.label_status->setStyleSheet("color:red");
			for (int i = 0; i < record_frame; i++) {
				qDebug() << FrameNum_cam1[i]<<"  "<<FrameNum_cam2[i]<<endl;
			}
			ui.label_status->setText(QString::fromLocal8Bit("相片采集完成,但没对齐"));
		}
	}
	else {
		ui.label_status->setStyleSheet("color:red");
		ui.label_status->setText(QString::fromLocal8Bit("没同时采集完成"));
	}
}
