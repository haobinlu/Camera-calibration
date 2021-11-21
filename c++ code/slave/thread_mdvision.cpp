#include "thread_mdvision.h"

thread_mdvision::thread_mdvision(int cam, string mode) {
	this->cam = cam;
	this->mode = mode;

	tSdkCameraCapbility sCameraInfo;
	int rate = 0;

	if ((status = CameraInit(&sCameraList[cam], -1, -1, &m_hCamera)) != CAMERA_STATUS_SUCCESS)
	{
		char msg[128];
		sprintf_s(msg, "Failed to init the camera! Error code is %d", status);
		printf(msg);
		printf(CameraGetErrorString(status));
	}
	CameraGetCapability(m_hCamera, &sCameraInfo);//"获得该相机的特性描述"
	if (sCameraInfo.sIspCapacity.bMonoSensor)
	{
		CameraSetIspOutFormat(m_hCamera, CAMERA_MEDIA_TYPE_MONO8);
		rate = 1;
	}
	else
	{
		CameraSetIspOutFormat(m_hCamera, CAMERA_MEDIA_TYPE_BGR8);
		rate = 3;
	}
	m_pFrameBuffer = (BYTE*)CameraAlignMalloc(sCameraInfo.sResolutionRange.iWidthMax*sCameraInfo.sResolutionRange.iWidthMax * rate, queue_size);
	CameraSetTriggerMode(m_hCamera, 2); // 0 连续触发 1 软件触发 2 硬件触发
	CameraSetAeState(m_hCamera, 0);
	CameraSetExposureTime(m_hCamera, 15 * 1000);
}

void thread_mdvision::run() {
	while (1) {
		status = CameraGetImageBuffer(m_hCamera, &sFrameInfo, &pbyBuffer, 1000);
		if (status == CAMERA_STATUS_SUCCESS) {
			qDebug() << "sucess";
			CameraImageProcess(m_hCamera, pbyBuffer, m_pFrameBuffer, &sFrameInfo);//连续模式
			//在成功调用CameraGetImageBuffer后，必须调用CameraReleaseImageBuffer来释放获得的buffer。
			//否则再次调用CameraGetImageBuffer时，程序将被挂起，知道其他线程中调用CameraReleaseImageBuffer来释放了buffer
			CameraReleaseImageBuffer(m_hCamera, pbyBuffer); 
			cv::Mat matImage(
				cvSize(sFrameInfo.iWidth, sFrameInfo.iHeight),
				sFrameInfo.uiMediaType == CAMERA_MEDIA_TYPE_MONO8 ? CV_8UC1 : CV_8UC3,
				m_pFrameBuffer
			);

			cv::resize(matImage, matImage_scale, Size(label_mdvision_weight, label_mdvision_height));
			QImage image(matImage_scale.data, label_mdvision_height, label_mdvision_weight, matImage_scale.step, QImage::Format_RGB888);
			QImage img = image.rgbSwapped();
			emit processed_QImage(img);
			////让SDK内部取图线程开始工作
			//CameraPlay(m_hCamera);

			if (recording) {
				QString str = QString("frame:%1 thread %2: %3").arg(r_t).arg((int)cam).arg(GetTickCount() / 1000);
				qDebug() << str;
				compelet = false;
				frame_ls.push_back(matImage);
				r_t += 1;
				if (r_t > record_frame) {
					utils->save_MdvisionVideos(frame_ls, cam, mode);
					r_t = 0;
					recording = false;
					compelet = true;
					frame_ls.clear();
				}
			}
		}
	}
}