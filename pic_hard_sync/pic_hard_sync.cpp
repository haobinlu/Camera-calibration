#include "pic_hard_sync.h"

pic_hard_sync::pic_hard_sync(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	label_RGB_height = ui.label_RGB_1->height();
	label_RGB_width = ui.label_RGB_1->width();

	utils->init_csv();

	start();
	qDebug() << "started" << endl;

	//注册用户
	connect(ui.pushButton_regist, SIGNAL(clicked()), this, SLOT(regist()));
	//删除用户
	connect(ui.pushButton_del, SIGNAL(clicked()), this, SLOT(del_user()));

	//主RGBD的显示线程
	thread_realsense1 = new mainthread_cam(cfg_list[camera_realsense_1_idx], camera_realsense_1_idx);
	connect(thread_realsense1, &mainthread_cam::processed_QImage, this, &pic_hard_sync::show_realsense_1);
	connect(thread_realsense1, &mainthread_cam::recordProgress, this, &pic_hard_sync::update_recordProgress);
	connect(thread_realsense1, &mainthread_cam::signal_check_compelet, this, &pic_hard_sync::check_compelet);

	////第二个RGBD的显示线程
	//thread_realsense2 = new thread_realsense(cfg_list[camera_realsense_2_idx], camera_realsense_2_idx);
	//connect(thread_realsense2, &thread_realsense::processed_QImage, this, &pic_hard_sync::show_realsense_2);

	////第三个RGBD的显示线程
	//thread_realsense3 = new thread_realsense(cfg_list[camera_realsense_3_idx], camera_realsense_3_idx);
	//connect(thread_realsense3, &thread_realsense::processed_QImage, this, &pic_hard_sync::show_realsense_3);

	////第四个RGBD的显示线程
	//thread_realsense4 = new thread_realsense(cfg_list[camera_realsense_4_idx], camera_realsense_4_idx);
	//connect(thread_realsense4, &thread_realsense::processed_QImage, this, &pic_hard_sync::show_realsense_4);

	////第四个RGBD的显示线程
	//thread_realsense5 = new thread_realsense(cfg_list[camera_realsense_5_idx], camera_realsense_5_idx);
	//connect(thread_realsense5, &thread_realsense::processed_QImage, this, &pic_hard_sync::show_realsense_5);

	////第四个RGBD的显示线程
	//thread_realsense6 = new thread_realsense(cfg_list[camera_realsense_6_idx], camera_realsense_6_idx);
	//connect(thread_realsense6, &thread_realsense::processed_QImage, this, &pic_hard_sync::show_realsense_6);

	//第四个RGBD的显示线程
	//thread_cam7 = new thread_cam(cfg_list[camera_realsense_7_idx], camera_realsense_7_idx);
	//connect(thread_cam7, &thread_cam::processed_QImage, this, &pic_hard_sync::show_frameset_7);

	thread_realsense1->start();
	//thread_realsense2->start();
	//thread_realsense3->start();
	//thread_realsense4->start();
	//thread_realsense5->start();
	//thread_realsense6->start();
	//thread_cam7->start();
}

void pic_hard_sync::start() {
	int count = sn_list.size();
	auto ctx = rs2::context();

	for (auto& device : std::vector<rs2::device>(ctx.query_devices())) {
		std::string sn = device.get_info(RS2_CAMERA_INFO_SERIAL_NUMBER);

		rs2::color_sensor color_sensor = device.first<rs2::color_sensor>();
		color_sensor.set_option(RS2_OPTION_FRAMES_QUEUE_SIZE, color_queue_size);

		rs2::depth_sensor depth_sensor = device.first<rs2::depth_sensor>();
		depth_sensor.set_option(RS2_OPTION_FRAMES_QUEUE_SIZE, depth_queue_size);

		vector<string>::iterator it = std::find(sn_list.begin(), sn_list.end(), sn);
		int dis = distance(sn_list.begin(), it);

		rs2::config c;
		c.enable_device(sn_list[dis]);
		c.enable_stream(RS2_STREAM_DEPTH, FRAME_WIDTH, FRAME_HEIGHT, RS2_FORMAT_Z16, fps);
		c.enable_stream(RS2_STREAM_COLOR, FRAME_WIDTH, FRAME_HEIGHT, RS2_FORMAT_BGR8, fps);
		cfg_list.push_back(c);


	}

	//for (int i = 0; i < count; i++)
	//{
	//	rs2::config c;
	//	c.enable_device(sn_list[i]);
	//	c.enable_stream(RS2_STREAM_DEPTH, FRAME_WIDTH, FRAME_HEIGHT, RS2_FORMAT_Z16, fps);
	//	c.enable_stream(RS2_STREAM_COLOR, FRAME_WIDTH, FRAME_HEIGHT, RS2_FORMAT_BGR8, fps);
	//	cfg_list.push_back(c);
	//}
}

void pic_hard_sync::regist() {
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
	thread_realsense1->recording = true;
	//thread_realsense2->recording = true;
	//thread_realsense3->recording = true;
	//thread_realsense4->recording = true;
	//thread_realsense5->recording = true;
	//thread_realsense6->recording = true;
	//thread_cam7->recording = true;
}

void pic_hard_sync::del_user() {
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

void pic_hard_sync::show_realsense_1(QImage data1, QImage data2) {
	ui.label_RGB_1->setPixmap(QPixmap::fromImage(data1));
	ui.label_RGB_7->setPixmap(QPixmap::fromImage(data2));
}
//
//void pic_hard_sync::show_realsense_2(QImage data1, QImage data2) {
//	ui.label_RGB_2->setPixmap(QPixmap::fromImage(data1));
//	ui.label_RGB_8->setPixmap(QPixmap::fromImage(data2));
//}
//
//void pic_hard_sync::show_realsense_3(QImage data1, QImage data2) {
//	ui.label_RGB_3->setPixmap(QPixmap::fromImage(data1));
//	ui.label_RGB_9->setPixmap(QPixmap::fromImage(data2));
//}
//
//void pic_hard_sync::show_realsense_4(QImage data1, QImage data2) {
//	ui.label_RGB_4->setPixmap(QPixmap::fromImage(data1));
//	ui.label_RGB_10->setPixmap(QPixmap::fromImage(data2));
//}
//
//void pic_hard_sync::show_realsense_5(QImage data1, QImage data2) {
//	ui.label_RGB_5->setPixmap(QPixmap::fromImage(data1));
//	ui.label_RGB_11->setPixmap(QPixmap::fromImage(data2));
//}
//
//void pic_hard_sync::show_realsense_6(QImage data1, QImage data2) {
//	ui.label_RGB_6->setPixmap(QPixmap::fromImage(data1));
//	ui.label_RGB_12->setPixmap(QPixmap::fromImage(data2));
//}

void pic_hard_sync::update_recordProgress(int value) {
	ui.progressBar->setValue(value);
}


void pic_hard_sync::check_compelet() {
	if (thread_realsense1->compelet) {
		int lost = -1;
		for (int i = 0; i < sn_list.size(); i++) {
			if (FrameNum_cam[i].back() != record_frame) {
				lost = i;
				break;
			}
		}
		if (lost == -1) {
			ui.label_status->setStyleSheet("color:green");
			ui.label_status->setText(QString::fromLocal8Bit("相片采集完成,没有漏帧"));
		}
		else
		{
			ui.label_status->setStyleSheet("color:red");
			//QByteArray &s = "相片采集完成," + to_string(lost) + "有漏帧";
			ui.label_status->setText(QString("collect complet,%1 has lost").arg((int)lost));
		}
	}
	else {
		ui.label_status->setStyleSheet("color:red");
		ui.label_status->setText(QString::fromLocal8Bit("没同时采集完成"));
	}
}