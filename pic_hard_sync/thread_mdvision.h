#pragma once
#include <QThread>
#include <QImage>
#include <QDebug>
//#include "opencv2/core/core.hpp"
//#include "opencv2/videoio/videoio.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/imgcodecs/imgcodecs.hpp"
//#include "opencv2/highgui/highgui.hpp"
#include <WinSock2.h>
#include <windows.h>
#include <sys/timeb.h>

#include "..//include//CameraApi.h"
#include "utils.h"
#include "stdafx.h"

using namespace std;

extern tSdkCameraDevInfo sCameraList[4];
extern int queue_size;
extern int FRAME_WIDTH;
extern int FRAME_HEIGHT;
extern int label_mdvision_height;
extern int label_mdvision_weight;
extern int record_frame;
extern int iWidth;
extern int iHeight;    //工业相机分辨率
extern int iAeTarget;  //工业相机目标亮度

class thread_mdvision : public QThread
{
	Q_OBJECT
public:
	thread_mdvision(int cam, string mode);

	bool recording = false;
	bool compelet = true;

protected:
	void run();


private:
	Utils *utils;

	int cam;
	string mode;
	CameraSdkStatus status;
	CameraHandle    m_hCamera;
	unsigned char*  m_pFrameBuffer; //用于将原始图像数据转换为RGB的缓冲区

	tSdkFrameHead 	sFrameInfo;
	BYTE* pbyBuffer;
	BYTE* g_readBuf; //显示数据buffer
	Mat matImage_scale;
	Mat matImage_scale_show;
	int r_t = 0;
	double time_out = 0.2;
	vector<Mat> frame_ls;
	vector<double> timestamps;
	QVector<QRgb> grayColourTable;
	timeb t;


signals:
	void processed_QImage(QImage);
};
