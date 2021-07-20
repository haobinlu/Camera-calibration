#pragma once
#include <iostream>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QTimer>
#include <QMetaType> 

#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include "opencv2\video\background_segm.hpp"
#include "opencv2\video\tracking.hpp"

#include<librealsense2/rs.hpp>
   
#include "ui_pic_collect.h"
#include "thread_cam.h"
#include "mainthread_process.h"
#include "thread_process.h"
#include "utils.h"

using namespace cv;
using namespace std;
using namespace rs2;

extern QString current_NO;
extern QString current_ID;
extern QString current_sex;
extern vector<string> user_sample_num_ls;
extern int FRAME_HEIGHT;
extern int FRAME_WIDTH;
extern int label_RGB_height; // RGBD相机彩色图像显示位置的高度
extern int label_RGB_width;


class pic_collect : public QMainWindow
{
    Q_OBJECT

public:
    pic_collect(QWidget *parent = Q_NULLPTR);

	int camera_RBGD_1_idx = 0;  // RGBD相机1 idx
	int camera_RBGD_2_idx = 1;  // RGBD相机2 idx


private slots:

	void pass_frameset_1(frameset);
	void pass_frameset_2(frameset);

	void show_frameset_1(QImage, QImage);
	void show_frameset_2(QImage, QImage);

	void update_recordProgress(int);
	void check_compelet();

	void regist();	
	void del_user();



private:
	Ui::pic_collectClass ui;
	Utils *utils;

	//处理的主线程
	thread_cam *thread_cam_1;
	mainthread_process *thread_process_1;

	thread_cam *thread_cam_2;
	thread_process *thread_process_2;

signals:
	void process_frameset(rs2::frameset);
};
