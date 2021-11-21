#include "utils.h"

Utils::Utils()
{

}

Utils::~Utils()
{

}

void Utils::RemoveAll(QString folderDir)
{
	QDir dir(folderDir);
	QFileInfoList fileList;
	QFileInfo curFile;
	if (!dir.exists()) {
		return;
	}//文件不存，则返回false
	fileList = dir.entryInfoList(QDir::Dirs | QDir::Files
		| QDir::Readable | QDir::Writable
		| QDir::Hidden | QDir::NoDotAndDotDot
		, QDir::Name);
	while (fileList.size() > 0)
	{
		int infoNum = fileList.size();
		for (int i = infoNum - 1; i >= 0; i--)
		{
			curFile = fileList[i];
			if (curFile.isFile())//如果是文件，删除文件
			{
				QFile fileTemp(curFile.filePath());
				fileTemp.remove();
				fileList.removeAt(i);
			}
			if (curFile.isDir())//如果是文件夹
			{
				QDir dirTemp(curFile.filePath());
				QFileInfoList fileList1 = dirTemp.entryInfoList(QDir::Dirs | QDir::Files
					| QDir::Readable | QDir::Writable
					| QDir::Hidden | QDir::NoDotAndDotDot
					, QDir::Name);
				if (fileList1.size() == 0)//下层没有文件或文件夹
				{
					dirTemp.rmdir(".");
					fileList.removeAt(i);
				}
				else//下层有文件夹或文件
				{
					for (int j = 0; j < fileList1.size(); j++)
					{
						if (!(fileList.contains(fileList1[j])))
							fileList.append(fileList1[j]);
					}
				}
			}
		}
	}
}

void Utils::save_Realsensevideos(vector<Mat> frame_ls, vector<int> FrameNum_ls, int cam) {

	QString str = QString("util thread id:%3").arg((int)QThread::currentThreadId());
	qDebug() << str;

	string root = root_path.toStdString();
	string cur_NO = current_NO.toStdString();
	string sample_path = root + "/sample_" + cur_NO + "/";
	if (access(sample_path.c_str(), 0) == -1)
		mkdir(sample_path.c_str());
	string sample_path_RGBD = sample_path + "RGBD_" + to_string(cam) + "/";
	if (access(sample_path_RGBD.c_str(), 0) == -1)
		mkdir(sample_path_RGBD.c_str());
	string sample_path_rgb = sample_path_RGBD + "rgb/";
	if (access(sample_path_rgb.c_str(), 0) == -1)
		mkdir(sample_path_rgb.c_str());
	string sample_path_depth = sample_path_RGBD + "depth/";
	if (_access(sample_path_depth.c_str(), 0) == -1)
		mkdir(sample_path_depth.c_str());

	int frame_len = (int)frame_ls.size() / 2;
	for (int i = 0; i < frame_len; i++) {

		string color_path = sample_path_rgb + to_string(FrameNum_ls[i]) + ".jpg";
		string depth_path = sample_path_depth + to_string(FrameNum_ls[i]) + ".jpg";

		imwrite(color_path, frame_ls[2 * i]);
		imwrite(depth_path, frame_ls[2 * i + 1]);
	}
}

void Utils::save_MdvisionVideos(vector<Mat> frame_ls, int cam, string mode) {

	QString str = QString("util thread id:%3").arg((int)QThread::currentThreadId());
	qDebug() << str;

	string root = root_path.toStdString();
	string cur_NO = current_NO.toStdString();
	string sample_path = root + "/sample_" + cur_NO + "/";
	if (access(sample_path.c_str(), 0) == -1)
		mkdir(sample_path.c_str());
	string sample_path_mode = sample_path + mode + "_" + to_string(cam) + "/";
	if (access(sample_path_mode.c_str(), 0) == -1)
		mkdir(sample_path_mode.c_str());

	int frame_len = (int)frame_ls.size();
	for (int i = 0; i < frame_len; i++) {

		string path = sample_path_mode + to_string(i) + ".jpg";

		imwrite(path, frame_ls[i]);
	}
}
