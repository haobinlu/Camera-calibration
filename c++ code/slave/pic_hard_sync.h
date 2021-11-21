#pragma once

#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QMetaType>

#include "ui_pic_hard_sync.h"
#include <vector>
#include <iostream>
# include  <algorithm>
#include<librealsense2/rs.hpp>

#include <WinSock2.h>
#include <windows.h>
#include "../include/CameraApi.h"

#include "mainthread_cam.h"
#include "thread_realsense.h"
#include "thread_mdvision.h"
#include "thread_Tcpslave.h"
#include "utils.h"

using namespace std;

extern QString current_NO;
extern vector<string> sn_list;
extern vector<vector<int>> FrameNum_cam;
extern int FRAME_HEIGHT;
extern int FRAME_WIDTH;
extern int label_RGB_height; // RGBD相机彩色图像显示位置的高度
extern int label_RGB_width;
extern int label_mdvision_height;  //工业相机图像显示的高度
extern int label_mdvision_weight;
extern int fps;
extern int record_frame;
extern int color_queue_size;
extern int depth_queue_size;
extern int mdvision_num;
//extern 	tSdkCameraDevInfo sCameraList[4];

class pic_hard_sync : public QMainWindow
{
	Q_OBJECT

public:
	pic_hard_sync(QWidget *parent = Q_NULLPTR);

	int camera_realsense_1_idx = 0;  // RGBD相机1 idx
	//int camera_realsense_2_idx = 1;  // RGBD相机2 idx
	//int camera_realsense_3_idx = 2;  // RGBD相机1 idx
	//int camera_realsense_4_idx = 3;  // RGBD相机2 idx
	//int camera_realsense_5_idx = 4;  // RGBD相机2 idx
	//int camera_realsense_6_idx = 5;  // RGBD相机1 idx
	//int camera_realsense_7_idx = 6;  // RGBD相机2 idx

	int camera_fisheye_1_idx = 0;  //鱼眼相机 idx


private slots:
	void show_realsense_1(QImage, QImage);
	//void show_realsense_2(QImage, QImage);
	//void show_realsense_3(QImage, QImage);
	//void show_realsense_4(QImage, QImage);
	//void show_realsense_5(QImage, QImage);
	//void show_realsense_6(QImage, QImage);
	//void show_frameset_7(QImage, QImage);

	//void show_fisheye_1(QImage);

	void update_recordProgress(int);
	void check_compelet();

	void regist();
	void del_user(QString);

	void show_TCP_status(string);

private:
	Ui::pic_hard_syncClass ui;
	Utils *utils;

	void start();

	mainthread_cam *thread_realsense1;
	//thread_realsense *thread_realsense2;
	//thread_realsense *thread_realsense3;
	//thread_realsense *thread_realsense4;
	//thread_realsense *thread_realsense5;
	//thread_realsense *thread_realsense6;
	//thread_cam *thread_cam7;

	//thread_mdvision *thread_fisheye1;

	thread_Tcpslave *thread_slave;

	vector<rs2::config> cfg_list;
};

