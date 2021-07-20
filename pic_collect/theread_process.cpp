#include "thread_process.h"

thread_process::thread_process(int cam) {
	this->cam = cam;

}


void thread_process::run() {
	while (1) {
		if (!isRunning) {
			QThread::msleep(10);
			continue;
		}
		else
		{
			rs2::frame color = data.get_color_frame();
			Mat color_image(Size(FRAME_WIDTH, FRAME_HEIGHT), CV_8UC3, (void*)color.get_data(), Mat::AUTO_STEP);
			cv::resize(color_image, color_image, Size(label_RGB_width, label_RGB_height));
			QImage image(color_image.data, label_RGB_height, label_RGB_width, color_image.step, QImage::Format_RGB888);
			QImage imgg = image.rgbSwapped();

			rs2::frame depth = data.get_depth_frame().apply_filter(color_map);
			Mat depth_image(Size(FRAME_WIDTH, FRAME_HEIGHT), CV_8UC3, (void*)depth.get_data(), Mat::AUTO_STEP);
			cv::resize(depth_image, depth_image, Size(label_RGB_width, label_RGB_height));
			QImage imaged(depth_image.data, label_RGB_height, label_RGB_width, depth_image.step, QImage::Format_RGB888);
			QImage imggd = imaged.rgbSwapped();

			emit processed_QImage(imgg, imggd);
			isRunning = false;
			if (issave) {
				if (r_t == 0) {

					start_frame = data.get_color_frame().get_frame_number();
				}
				QString str = QString("frame:%1 thread %3: %4").arg(data.get_color_frame().get_frame_number() - start_frame).arg((int)cam).arg(data.get_timestamp() / 1000, 0, 'Q', 4);
				qDebug() << str;
				compelet = false;
				frame_ls.push_back(color_image);
				frame_ls.push_back(depth_image);
				FrameNum_ls.push_back(data.get_color_frame().get_frame_number() - start_frame);
				r_t += 1;
				if (r_t == record_frame) {
					utils->save_videos(frame_ls, FrameNum_ls, cam);
					r_t = 0;
					issave = false;
					compelet = true;
					FrameNum_cam1 = FrameNum_ls;
					frame_ls.clear();
					FrameNum_ls.clear();
				}
			}
		}
	}

}
