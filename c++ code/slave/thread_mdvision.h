#pragma once
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
	Mat matImage_scale;
	int r_t = 0;
	vector<Mat> frame_ls;

signals:
	void processed_QImage(QImage);
};
