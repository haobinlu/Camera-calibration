#include "pic_hard_sync.h"

pic_hard_sync::pic_hard_sync(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	label_RGB_height = ui.label_RGB_1->height();
	label_RGB_width = ui.label_RGB_1->width();
	label_mdvision_height = ui.label_gray_fisheye_1->height();
	label_mdvision_weight = ui.label_gray_fisheye_1->width();

	start();
	qDebug() << "started" << endl;

	qRegisterMetaType<std::string>("std::string");

	//删除用户
	//connect(ui.pushButton_del, SIGNAL(clicked()), this, SLOT(del_user()));

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

	//thread_fisheye1 = new thread_mdvision(camera_fisheye_1_idx, "fisheye");


	thread_slave = new thread_Tcpslave();
	//注册用户
	connect(thread_slave, &thread_Tcpslave::slave_record, this, &pic_hard_sync::regist);
	connect(thread_slave, &thread_Tcpslave::TCP_status, this, &pic_hard_sync::show_TCP_status);
	connect(thread_slave, &thread_Tcpslave::slave_del, this, &pic_hard_sync::del_user);

	thread_realsense1->start();
	//thread_realsense2->start();
	//thread_realsense3->start();
	//thread_realsense4->start();
	//thread_realsense5->start();
	//thread_realsense6->start();
	//thread_cam7->start();

	//thread_fisheye1->start();

	thread_slave->start();
}

void pic_hard_sync::start() {
	//初始化realsense
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

	//初始化mindvision
	if (CameraEnumerateDevice(sCameraList, &mdvision_num) != CAMERA_STATUS_SUCCESS || mdvision_num == 0)
	{
		printf("No camera was found!");
	}
}

void pic_hard_sync::regist() {
	ui.lineEdit_NO->setText(current_NO);
	thread_realsense1->recording = true;
	//thread_realsense2->recording = true;
	//thread_realsense3->recording = true;
	//thread_realsense4->recording = true;
	//thread_realsense5->recording = true;
	//thread_realsense6->recording = true;
	//thread_cam7->recording = true;

	//thread_fisheye1->recording = true;
}

void pic_hard_sync::del_user(QString user) {
	ui.lineEdit_NO->setText("");
	ui.label_TCP_status->setText(QString::fromLocal8Bit("等待下一次采集"));
	ui.label_status->clear();
	//删除该用户的整个文件夹
	QString dir_path = root_path + "/sample_" + current_NO + "/";
	QDir dir(dir_path);
	dir.removeRecursively();
	current_NO = "";
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

//void pic_hard_sync::show_fisheye_1(QImage data1) {
//	ui.label_gray_fisheye_1->setPixmap(QPixmap::fromImage(data1));
//}

void pic_hard_sync::update_recordProgress(int value) {
	ui.progressBar->setValue(value);
}

void pic_hard_sync::show_TCP_status(string s) {

	ui.label_TCP_status->setText(QString::fromLocal8Bit(s.c_str()));
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
	ui.label_TCP_status->setText(QString::fromLocal8Bit("等待下一次采集"));
}