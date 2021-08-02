#include <iostream>
#include <vector>
#include <QImage>
#include <QString>

using namespace std;


//其他设置
//realsense
int record_frame = 125;
int fps = 30;
int color_queue_size = 8; 
int depth_queue_size = 8;
int FRAME_WIDTH = 848;
int FRAME_HEIGHT = 480;
int label_RGB_height; // RGBD相机彩色图像显示位置的高度
int label_RGB_width;

//工业相机


QString root_path = "../data";
string information_csv_path = "../data/user_info.csv";
QString current_NO = "";
QString current_ID = "";
QString current_sex = "";

string c1 = "022422071955";
string c2 = "944622073140";
string c3 = "050522073055";
string c4 = "927522072943";
string c5 = "104422071176";
string c6 = "104422071104";
string c7 = "104422071156";
string c8 = "104422070884";
string c9 = "104422070397";
string c10 = "045322075125";
string c11 = "104422070836";
string c12 = "104422071182";

vector<string> sn_list = {c7};
vector<string> user_sample_num_ls;
vector<vector<int>> FrameNum_cam(16);
