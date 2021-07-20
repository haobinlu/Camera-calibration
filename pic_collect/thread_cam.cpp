#include "thread_cam.h"

thread_cam::thread_cam(int cam) {

	this->cam = cam;

	qRegisterMetaType< rs2::frameset >("frameset");

	pipe_config.enable_device(sn_list[cam]);
	pipe_config.enable_stream(RS2_STREAM_DEPTH, FRAME_WIDTH, FRAME_HEIGHT, RS2_FORMAT_Z16, fps);
	pipe_config.enable_stream(RS2_STREAM_COLOR, FRAME_WIDTH, FRAME_HEIGHT, RS2_FORMAT_BGR8, fps);
	profile = pipe.start(pipe_config);

}

void thread_cam::run() {
	QString str = QString("thread id:%3").arg((int)QThread::currentThreadId());
	while (true) {
		data = pipe.wait_for_frames();  //µÈ´ýÏÂÒ»Ö¡
		rs2::align align(rs2_stream::RS2_STREAM_COLOR); // align depth and rgb image
		data = align.process(data);
		emit signal_frameset(data);
	}
}