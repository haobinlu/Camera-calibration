#include "thread_realsense.h"

thread_realsense::thread_realsense(rs2::config cfg, int cam) {
	pipe.start(cfg);
	this->cam = cam;
}

void thread_realsense::run() {
	int start = 0;
	rs2_stream align_to = RS2_STREAM_COLOR;
	rs2::align align(align_to);

	while (true)
	{
		frame = pipe.wait_for_frames();  //等待下一帧
		auto processed = align.process(frame);

		rs2::frame depth = processed.get_depth_frame();
		if (depth.get_frame_number() == last_frame_num) {
			continue;
		}
		last_frame_num = depth.get_frame_number();

		rs2::frame color = processed.get_color_frame();
		Mat color_image(Size(FRAME_WIDTH, FRAME_HEIGHT), CV_8UC3, (void*)color.get_data(), Mat::AUTO_STEP);
		cv::resize(color_image, color_image_scale, Size(label_RGB_width, label_RGB_height));
		QImage imagec(color_image_scale.data, label_RGB_width, label_RGB_height,  color_image_scale.step, QImage::Format_RGB888);
		QImage imgc = imagec.rgbSwapped();

		
		Mat depth_image(Size(FRAME_WIDTH, FRAME_HEIGHT), CV_16UC1, (void*)depth.get_data(), Mat::AUTO_STEP);
		cv::convertScaleAbs(depth_image, depth_image_8U);
		cv::resize(depth_image_8U, depth_image_scale, Size(label_RGB_width, label_RGB_height));
		QImage imaged(depth_image_scale.data, label_RGB_width, label_RGB_height,  depth_image_scale.step, QImage::Format_Indexed8);

		emit processed_QImage(imgc, imaged);
		ftime(&t);//获取毫秒
		if (recording) {
			if (r_t == 0) {
				start = depth.get_frame_number();
			}
			int current_frame = depth.get_frame_number() - start;

			double current_t = t.time * 1000 + t.millitm;

			QString str = QString("frame:%1 thread %3: %4").arg(current_frame).arg((int)cam).arg(depth.get_timestamp() / 1000, 0, 'Q', 4);
			qDebug() << str;
			compelet = false;
			Mat color_img;
			Mat depth_img;
			color_image.copyTo(color_img);
			depth_image.copyTo(depth_img);
			frame_ls.push_back(color_img);
			frame_ls.push_back(depth_img);
			FrameNum_ls.push_back(current_frame);
			timestamps.push_back(current_t);
			r_t += 1;
			if (r_t >= record_frame) {
				utils->save_Realsensevideos(frame_ls, timestamps, FrameNum_ls, cam);
				r_t = 0;
				recording = false;
				compelet = true;
				frame_ls.clear();
				FrameNum_ls.clear();
				timestamps.clear();
			}
		}
	}
}