#include <iostream>
#include <vector>
#include <QImage>
#include <QString>

using namespace std;


//其他设置
int record_frame = 12;
int fps = 15;
int FRAME_HEIGHT = 480;
int FRAME_WIDTH = 640;
int label_RGB_height; // RGBD相机彩色图像显示位置的高度
int label_RGB_width;

QString root_path = "../data";
string information_csv_path = "../data/user_info.csv";
QString current_NO = "";
QString current_ID = "";
QString current_sex = "";

vector<string> sn_list = { "022422071955", "104422070836" };
vector<string> user_sample_num_ls;
vector<int> FrameNum_cam1;
vector<int> FrameNum_cam2;