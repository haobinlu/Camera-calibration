#pragma once

#include <QThread>
#include <QTimer>
#include <qdir.h>
#include <QDebug>
#include <QImage>

#include "opencv2/core/core.hpp"
#include "opencv2/videoio/videoio.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <io.h>
#include <direct.h>
#include <fstream>
#include <string> 

#include<librealsense2/rs.hpp>

using namespace cv;
using namespace std;

extern QString current_NO;
extern QString root_path;
extern vector<string> user_sample_num_ls;

class Utils
{
public:
	Utils();
	~Utils();
	void save_Realsensevideos(vector<Mat>, vector<int>, int);
	void save_MdvisionVideos(vector<Mat>, int, string);
	void RemoveAll(QString);
};
