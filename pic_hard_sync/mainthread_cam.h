#pragma once
#pragma once

#include <QThread>
#include <QImage>
#include <QDebug>
#include<librealsense2/rs.hpp>
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/videoio/videoio.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include<windows.h>
#include <sys/timeb.h>

#include "utils.h"

using namespace std;
using namespace cv;

extern int FRAME_HEIGHT;
extern int FRAME_WIDTH;
extern int label_RGB_height; // RGBD相机彩色图像显示位置的高度
extern int label_RGB_width;
extern int record_frame;

class mainthread_cam : public QThread
{
	Q_OBJECT
public:

	mainthread_cam(rs2::config cfg, int cam);

	bool recording = false;
	bool compelet = true;

protected:
	void run();


private:
	Utils *utils;

	rs2::colorizer color_map;
	rs2::pipeline pipe;
	rs2::frameset frame;

	vector<Mat> frame_ls;
	vector<int> FrameNum_ls;
	vector<double> timestamps;

	Mat color_image_scale;
	Mat depth_image_scale;
	Mat depth_image_8U;

	int r_t = 0;
	int cam;
	int last_frame_num = -1;
	timeb t;

signals:
	void processed_QImage(QImage, QImage);
	void recordProgress(int);
	void signal_check_compelet(bool);
};