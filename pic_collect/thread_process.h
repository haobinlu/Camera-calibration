#pragma once

#include <QThread>
#include <QTimer>
#include "opencv2/core/core.hpp"
#include "opencv2/videoio/videoio.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QDebug>
#include <QImage>
#include <windows.h>
#include <iostream>
#include <vector>
#include <list>
#include <QMetaType>

#include<librealsense2/rs.hpp>

#include "utils.h"

using namespace cv;
using namespace std;

extern int FRAME_HEIGHT;
extern int FRAME_WIDTH;
extern int label_RGB_height; // RGBD相机彩色图像显示位置的高度
extern int label_RGB_width;
extern int record_frame;
extern vector<int> FrameNum_cam1;

class thread_process : public QThread
{
	Q_OBJECT
public:
	vector<Mat> frame_ls;
	vector<int> FrameNum_ls;
	thread_process(int cam);
	rs2::frameset data;
	bool isRunning = false;
	bool issave = false;
	bool compelet = true;

protected:
	void run();

private:
	Utils *utils;

	int cam;
	rs2::colorizer color_map;
	int r_t = 0;
	int start_frame;

signals:
	void processed_QImage(QImage, QImage);


};