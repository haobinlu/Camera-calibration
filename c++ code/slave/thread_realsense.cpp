#include "thread_realsense.h"

thread_realsense::thread_realsense(rs2::config cfg, int cam) {
	pipe.start(cfg);
	this->cam = cam;
}

void thread_realsense::run() {
	int start = 0;
	while (true)
	{
		frame = pipe.wait_for_frames();  //µÈ´ýÏÂÒ»Ö¡
		rs2::frame color = frame.get_color_frame();
		if (color.get_frame_number() == last_frame_num) {
			continue;
		}

		last_frame_num = color.get_frame_number();

		Mat color_image(Size(FRAME_WIDTH, FRAME_HEIGHT), CV_8UC3, (void*)color.get_data(), Mat::AUTO_STEP);
		cv::resize(color_image, color_image_scale, Size(label_RGB_width, label_RGB_height));
		QImage imagec(color_image_scale.data, label_RGB_height, label_RGB_width, color_image_scale.step, QImage::Format_RGB888);
		QImage imgc = imagec.rgbSwapped();

		rs2::frame depth = frame.get_depth_frame().apply_filter(color_map);
		Mat depth_image(Size(FRAME_WIDTH, FRAME_HEIGHT), CV_8UC3, (void*)depth.get_data(), Mat::AUTO_STEP);
		cv::resize(depth_image, depth_image_scale, Size(label_RGB_width, label_RGB_height));
		QImage imaged(depth_image_scale.data, label_RGB_height, label_RGB_width, depth_image_scale.step, QImage::Format_RGB888);
		QImage imggd = imaged.rgbSwapped();

		emit processed_QImage(imgc, imggd);

		if (recording) {
			if (r_t == 0) {
				start = color.get_frame_number();
			}
			int current_frame = color.get_frame_number() - start;
			QString str = QString("frame:%1 thread %3: %4").arg(current_frame).arg((int)cam).arg(color.get_timestamp() / 1000, 0, 'Q', 4);
			qDebug() << str;
			compelet = false;
			frame_ls.push_back(color_image);
			frame_ls.push_back(depth_image);
			FrameNum_ls.push_back(current_frame);
			r_t += 1;
			if (r_t > record_frame) {
				utils->save_Realsensevideos(frame_ls, FrameNum_ls, cam);
				r_t = 0;
				recording = false;
				compelet = true;
				FrameNum_cam[cam] = FrameNum_ls;
				frame_ls.clear();
				FrameNum_ls.clear();
			}
		}
	}
}