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

extern vector<string> sn_list;
extern int fps;
extern int FRAME_HEIGHT;
extern int FRAME_WIDTH;

Q_DECLARE_METATYPE(rs2::frameset);

class thread_cam : public QThread
{
	Q_OBJECT
public:

	thread_cam(int cam);
	
protected:
	void run();


private:
	//pic_collect *pc;
	QTimer *timer;
	Utils *utils;
	
	rs2::pipeline pipe;    //声明realsense管道
	rs2::config pipe_config;  //数据流配置信息
	rs2::pipeline_profile profile;
	rs2::frameset data;
	int cam;

signals:
	void signal_frameset(rs2::frameset);
};