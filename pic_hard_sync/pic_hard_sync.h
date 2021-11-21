#pragma once

#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <QtWidgets/QMessageBox>

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
#include "utils.h"

using namespace std;

extern QString current_ID;
extern QString current_gestureID;
extern QString current_gestureNO;
extern vector<string> user_sample_num_ls;
extern vector<string> sn_list;
extern vector<int> FrameNum_cam;
extern int FRAME_HEIGHT;
extern int FRAME_WIDTH;
extern int label_RGB_height; // RGBD相机彩色图像显示位置的高度
extern int label_RGB_width;
extern int label_mdvision_height; //工业相机显示位置的高度
extern int label_mdvision_weight;
extern int fps;
extern int record_frame;
extern int color_queue_size;
extern int depth_queue_size;
extern int mdvision_num;
extern int iAeTarget;

class pic_hard_sync : public QMainWindow
{
	Q_OBJECT

public:
	pic_hard_sync(QWidget *parent = Q_NULLPTR);

	int camera_RBGD_1_idx = 0;  // RGBD相机1 idx
	int camera_RBGD_2_idx = 1;  // RGBD相机2 idx
	int camera_RBGD_3_idx = 2;  // RGBD相机3 idx
	int camera_RBGD_4_idx = 3;  // RGBD相机4 idx
	int camera_RBGD_5_idx = 4;  // RGBD相机5 idx
	int camera_RBGD_6_idx = 5;  // RGBD相机6 idx
	int camera_RBGD_7_idx = 6;  // RGBD相机7 idx
	int camera_RBGD_8_idx = 7;  // RGBD相机8 idx
	//int camera_RBGD_9_idx = 8;  // RGBD相机9 idx
	//int camera_RBGD_10_idx = 9;  // RGBD相机10 idx

	int camera_fisheye_1_idx = 0;  //鱼眼相机 idx
	int camera_fisheye_2_idx = 1;  //鱼眼相机 idx
	int camera_fisheye_3_idx = 2;  //鱼眼相机 idx
	int camera_fisheye_4_idx = 3;  //鱼眼相机 idx


private slots:
	void show_realsense_1(QImage, QImage);
	void show_realsense_2(QImage, QImage);
	void show_realsense_3(QImage, QImage);
	void show_realsense_4(QImage, QImage);
	void show_realsense_5(QImage, QImage);
	void show_realsense_6(QImage, QImage);
	void show_realsense_7(QImage, QImage);
	void show_realsense_8(QImage, QImage);
	//void show_realsense_9(QImage, QImage);
	//void show_realsense_10(QImage, QImage);

	void show_fisheye_1(QImage);
	void show_fisheye_2(QImage);
	void show_fisheye_3(QImage);
	void show_fisheye_4(QImage);

	void update_recordProgress(int);
	void check_compelet();

	void regist();
	void del_user();
	void iAeTarget_change();
	void FrameRate_change();

private:
	Ui::pic_hard_syncClass ui;
	Utils *utils;

	void start();

	mainthread_cam *thread_realsense1;
	thread_realsense *thread_realsense2;
	thread_realsense *thread_realsense3;
	thread_realsense *thread_realsense4;
	thread_realsense *thread_realsense5;
	thread_realsense *thread_realsense6;
	thread_realsense *thread_realsense7;
	thread_realsense *thread_realsense8;
	//thread_realsense *thread_realsense9;
	//thread_realsense *thread_realsense10;

	thread_mdvision *thread_fisheye1;
	thread_mdvision *thread_fisheye2;
	thread_mdvision *thread_fisheye3;
	thread_mdvision *thread_fisheye4;


	vector<rs2::config> cfg_list;

};

