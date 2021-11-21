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

extern QString current_ID;
extern QString current_gestureID;
extern QString current_gestureNO;
extern QString root_path;
extern string information_csv_path;
extern vector<string> user_sample_num_ls;
extern vector<int> FrameNum_cam;

class Utils
{
public:
	Utils();
	~Utils();
	void save_Realsensevideos(vector<Mat>, vector<double>, vector<int>, int);
	void save_MdvisionVideos(vector<double>, vector<Mat>, int, string);
	void init_csv();
	void add_id();
	void RemoveAll(QString);
};
