#include <iostream>
#include <vector>
#include <QImage>
#include <QString>
#include "windows.h"
#include "..//include//CameraApi.h"

using namespace std;


//其他设置
//realsense
int record_frame = 150;
int fps = 15;
int color_queue_size = 8; 
int depth_queue_size = 8;
int FRAME_WIDTH = 1280;
int FRAME_HEIGHT = 720;
//int iWidth = 1920;
//int iHeight = 1080;    //工业相机分辨率
int label_RGB_height; // RGBD相机彩色图像显示位置的高度
int label_RGB_width;
int label_mdvision_height;
int label_mdvision_weight;
int iAeTarget = 40;   //工业相机目标亮度

//工业相机
int queue_size = 32;
tSdkCameraDevInfo sCameraList[4];

QString root_path = "../data";
string information_csv_path = "../data/user_info.csv";
QString current_ID = "";
QString current_gestureID = "";
QString current_gestureNO = "";

//string c1 = "134322070534";
//string c2 = "104422070884";
string c3 = "134222070118";
string c4 = "927522072943";
string c5 = "104422071176";
string c6 = "104422071104";
//string c7 = "134322071784"; 深度图有问题
string c8 = "045322075125";
string c9 = "104422070397";
//string c10 = "104422071182";
string c11 = "134322070536";
string c12 = "944622073140";

vector<string> sn_list = {c3, c4, c5, c6, c8, c9, c11, c12};
//vector<string> sn_list = {c3,c4};
vector<string> user_sample_num_ls;
vector<int> FrameNum_cam(16);
int mdvision_num = 4;