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
	CameraGetCapability(m_hCamera, &sCameraInfo);//"��ø��������������"
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
	CameraSetTriggerMode(m_hCamera, 2); // 0 �������� 1 ������� 2 Ӳ������
	CameraSetAeState(m_hCamera, 1);
	CameraSetExposureTime(m_hCamera, 15 * 1000);
	CameraPlay(m_hCamera);
}

void thread_mdvision::run() {
	while (1) {
		status = CameraGetImageBuffer(m_hCamera, &sFrameInfo, &pbyBuffer, (int)1000 * time_out);
		CameraSetAeTarget(m_hCamera, iAeTarget);
		if (status == CAMERA_STATUS_SUCCESS) {
			CameraImageProcess(m_hCamera, pbyBuffer, m_pFrameBuffer, &sFrameInfo);//����ģʽ
			//�ڳɹ�����CameraGetImageBuffer�󣬱������CameraReleaseImageBuffer���ͷŻ�õ�buffer��
			//�����ٴε���CameraGetImageBufferʱ�����򽫱�����֪�������߳��е���CameraReleaseImageBuffer���ͷ���buffer
			CameraReleaseImageBuffer(m_hCamera, pbyBuffer);
			// ����SDK���������Ĭ���Ǵӵ׵����ģ�ת��ΪOpencvͼƬ��Ҫ��һ�´�ֱ����
			CameraFlipFrameBuffer(m_pFrameBuffer, &sFrameInfo, 1);
			if (sFrameInfo.uiMediaType == CAMERA_MEDIA_TYPE_MONO8) {
				cv::Mat matImage(cvSize(sFrameInfo.iWidth, sFrameInfo.iHeight), CV_8UC1, m_pFrameBuffer);
				//cv::resize(matImage, matImage_scale, Size(iWidth, iHeight));
				cv::resize(matImage, matImage_scale_show, Size(label_mdvision_weight, label_mdvision_height));
				QImage image(matImage_scale_show.data, label_mdvision_weight, label_mdvision_height, matImage_scale_show.step, QImage::Format_Indexed8);
				image.setColorTable(grayColourTable);

				emit processed_QImage(image);
				////��SDK�ڲ�ȡͼ�߳̿�ʼ����
				//CameraPlay(m_hCamera);
				ftime(&t);//��ȡ����

				if (recording) {
					double current_t = t.time * 1000 + t.millitm;
					QString str = QString("frame:%1 thread %2: %3").arg(r_t).arg((int)cam + 11).arg(current_t);
					qDebug() << str;
					compelet = false;
					Mat img;
					matImage.copyTo(img);
					frame_ls.push_back(img);
					timestamps.push_back(current_t);
					r_t += 1;
					if (r_t >= record_frame) {
						utils->save_MdvisionVideos(timestamps, frame_ls, cam, mode);
						r_t = 0;
						recording = false;
						compelet = true;
						frame_ls.clear();
						timestamps.clear();
					}
				}
			}
			else
			{
				cv::Mat matImage(cvSize(sFrameInfo.iWidth, sFrameInfo.iHeight), CV_8UC3, m_pFrameBuffer);
				//cv::resize(matImage, matImage_scale, Size(iWidth, iHeight));
				cv::resize(matImage, matImage_scale_show, Size(label_mdvision_weight, label_mdvision_height));
				QImage image(matImage_scale_show.data, label_mdvision_weight, label_mdvision_height, matImage_scale_show.step, QImage::Format_RGB888);
				QImage imgc = image.rgbSwapped();

				emit processed_QImage(imgc);
				////��SDK�ڲ�ȡͼ�߳̿�ʼ����
				//CameraPlay(m_hCamera);
				ftime(&t);//��ȡ����
				if (recording) {
					double current_t = t.time * 1000 + t.millitm;
					QString str = QString("frame:%1 thread %2: %3").arg(r_t).arg((int)cam + 11).arg(current_t);
					qDebug() << str;
					compelet = false;
					Mat img;
					matImage.copyTo(img);
					frame_ls.push_back(img);
					timestamps.push_back(current_t);
					r_t += 1;
					if (r_t >= record_frame) {
						utils->save_MdvisionVideos(timestamps, frame_ls, cam, mode);
						r_t = 0;
						recording = false;
						compelet = true;
						frame_ls.clear();
						timestamps.clear();
					}
				}
			}		
		}
	}
}