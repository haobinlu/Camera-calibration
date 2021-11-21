# -*- coding: utf-8 -*-
# @Author  : Wanglu
# @Time    : 2021/06/24 11:29

import logging
from PyQt5 import QtCore, QtWidgets
from PyQt5.QtGui import QPixmap, QImage, QMovie
from PyQt5.QtWidgets import QFileDialog, QMessageBox
import sys
import cv2
import pandas as pd
import os, shutil
os.environ["KMP_DUPLICATE_LIB_OK"]  =  "TRUE"

from ui.main_UI import Ui_MainWindow
from src.utils import Utils
from src.my_thread.RGB_1_Thread import RGB_1_Thread
from src.my_thread.RGB_2_Thread import RGB_2_Thread

class Nothing():
    def __init__(self):
        pass

class MainWindow(QtWidgets.QMainWindow):

    # 更新进度条函数
    def atfn_update_recordProgress(self, num):
        self.ui.progressBar.setValue(num)

    def atfn_RGB_changeFrame(self, lst):  # lst第一位为图片cv2的BGR图片, 第二位为字符串mode
        img, pos= lst[0], lst[1]
        img = cv2.flip(img, 1)
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        img = cv2.resize(img, (self.label_RGB_height, self.label_RGB_width))
        img = QImage(img, self.label_RGB_height, self.label_RGB_width, QImage.Format_RGB888)
        img = QPixmap.fromImage(img)
        pos.setPixmap(img)

    def signal_label_statu_process(self, list):
        color, msg, r_t = list
        if color != None:
            self.ui.label_status.setStyleSheet("color:{}".format(color))
        if r_t != None:
            self.ui.label_status.setText("已注册{}/{}".format(r_t, self.total_recording_time))
        else:
            self.ui.label_status.setText(msg)

    def check_compelet(self):
        if self.RGB_1_th.compelet and self.RGB_2_th.compelet:
            self.ui.label_status.setStyleSheet("color:{}".format('green'))
            self.ui.label_status.setText('注册完成')
        # else:
        #     QMessageBox.warning(self, "Warning", "注册失败")
        #     self.del_user()
        #     self.ui.label_status.clear()

    def regist(self):
        self.current_NO = self.ui.lineEdit_NO.text()
        self.current_ID = self.ui.lineEdit_ID.text()
        self.current_sex = self.ui.comboBox_sex.currentText()
        if self.current_NO == '' or self.current_ID == '' or self.current_sex == '':
            QMessageBox.warning(self, "Warning", "当前用户信息不全，请重新填写")
            return
        else:
            self.current_NO = "%05d" % (int(self.ui.lineEdit_NO.text()))
            if self.current_NO in self.utils.user_sample_num_ls:
                reply = QMessageBox.question(self, "Question", "当前用户已注册完成, 如需重新注册请按确定继续", QMessageBox.Ok | QMessageBox.Close, QMessageBox.Close)
                if reply != QtWidgets.QMessageBox.Ok:
                    return

            print('开始注册')
            self.conf.current_NO = self.current_NO
            self.conf.current_ID = self.current_ID
            self.conf.current_sex = self.current_sex

            self.RGB_1_th.recording = 1
            self.RGB_2_th.recording = 1

    def del_user(self):
        self.current_NO = self.ui.lineEdit_NO.text()
        if self.current_NO == '' :
            QMessageBox.warning(self, "Warning", "请选择需要删除的用户")
            return
        else:
            self.current_NO = "%05d" % (int(self.ui.lineEdit_NO.text()))
            if self.current_NO in self.utils.user_sample_num_ls:
                self.ui.lineEdit_NO.setText('')
                self.ui.lineEdit_ID.setText('')
                self.ui.label_status.clear()
                self.utils.user_sample_num_ls.remove(self.current_NO)
                #删除该用户的整个文件夹
                shutil.rmtree(os.path.join(self.root_path, "sample_%s" % (self.current_NO)))
                df = pd.read_csv(self.utils.information_csv_path, dtype=str)
                for i in range(df.shape[0]):
                    if df.values[i, 0] == self.current_NO:
                        df.drop(df.index[i], inplace=True)
                        df.to_csv(self.utils.information_csv_path, index=False)
                self.current_NO = ''
                self.current_ID = ''
                self.current_sex = ''
            else:
                QMessageBox.warning(self, "Warning", "该用户未注册，请检查信息是否正确")
                return

    def calibration_camera_1_changed(self):
        self.calibration_cam_1 = self.ui.comboBox_calibration_camera_1.currentIndex()

    def calibration_camera_2_changed(self):
        self.calibration_cam_2 = self.ui.comboBox_calibration_camera_2.currentIndex()

    def start_calibration(self):
        # if self.calibration_cam_1 == self.calibration_cam_2:
        #     QMessageBox.warning(self, "Warning", "请选择不相同的两个相机进行标定")
        #     return
        # else:
        #     pass
        self.RGB_1_th.recording = 2
        self.RGB_2_th.recording = 2
        while(1):
            if self.RGB_1_th.recording == 0:
                QMessageBox.warning(self, "Warning", "完成采集")
                return
    def sample_frame_changed(self):
        try:
            self.sample_frame = int(self.ui.lineEdit_sample_frame.text())
            print('将采样帧数改成了{}'.format(self.sample_frame))
        except:
            return

    def FPS_changed(self):
        try:
            self.FPS = int(self.ui.lineEdit_FPS.text())
            print('将FPS改成了{}'.format(self.FPS))
        except:
            return

    def total_recording_time_changed(self):
        try:
            self.total_recording_time = int(self.ui.lineEdit_total_recording_time.text())
            print('将注册次数改成了{}'.format(self.total_recording_time))
        except:
            return

    def select_path(self):
        self.fpath = QFileDialog.getExistingDirectory(self, "选择保存视频的根目录", "../")
        if self.fpath == '':
            QMessageBox.warning(self, "Warning", "请选择需要保存的路径")
            return
        self.ui.label_root_path.setText(self.fpath)


    def __init__(self):
        super(MainWindow, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        '''
        摄像头参数设置
        '''
        # self.camera_gray_fisheye_1_idx = 0  # 灰度鱼眼相机1 idx
        # self.camera_gray_fisheye_2_idx = 1  # 灰度鱼眼相机2 idx
        # self.camera_RGB_fisheye_1_idx = 2  # RGB鱼眼相机1 idx
        # self.camera_RGB_fisheye_2_idx = 3  # RGB鱼眼相机2 idx
        # self.camera_RBGD_1_idx = 4  # RGBF相机1 idx
        # self.camera_RBGD_2_idx = 5  # RGBF相机2 idx
        # self.camera_RBGD_3_idx = 6  # RGBF相机3 idx
        # self.camera_RBGD_4_idx = 7  # RGBF相机4 idx
        # self.camera_RBGD_5_idx = 8  # RGBF相机5 idx
        # self.camera_RBGD_6_idx = 9  # RGBF相机6 idx
        # self.camera_RBGD_7_idx = 10  # RGBF相机7 idx
        # self.camera_RBGD_8_idx = 11  # RGBF相机8 idx
        # self.camera_RBGD_9_idx = 12  # RGBF相机9 idx
        # self.camera_RBGD_10_idx = 13  # RGBF相机10 idx
        # self.camera_RBGD_11_idx = 14  # RGBF相机11 idx
        # self.camera_RBGD_12_idx = 15  # RGBF相机12 idx
        self.total_ready_time = 30  # 采集手势之前的等待时间，用来给用户做好准备（帧率计算）

        #测试用
        self.camera_RBGD_1_idx = 0  # RGBF相机1 idx
        self.camera_RBGD_2_idx = 1  # RGBF相机1 idx

        self.CAP_PROP_FRAME_HEIGHT = 480  # 采集图片的HEIGHT
        self.CAP_PROP_FRAME_WIDTH = 640  # 采集图片的WIDTH
        self.label_RGB_height = self.ui.label_RGB_1.geometry().height()  # 图像显示位置的高度
        self.label_RGB_width = self.ui.label_RGB_1.geometry().width()

        '''
        其他设置
        '''
        self.sample_frame = int(self.ui.lineEdit_sample_frame.text())  #单次采样帧数
        self.FPS = int(self.ui.lineEdit_FPS.text()) #采样时的FPS
        self.total_recording_time = int(self.ui.lineEdit_total_recording_time.text())
        self.root_path = self.ui.label_root_path.text() #视频存放的root文件夹
        self.current_NO = None   #当前注册用户的sample序列
        self.current_ID = None   #当前注册用户的ID
        self.current_sex = None  #当前注册用户的性别
        self.calibration_cam_1 = self.ui.comboBox_calibration_camera_1.currentIndex()  #需要标定的相机1
        self.calibration_cam_2 = self.ui.comboBox_calibration_camera_2.currentIndex()  # 需要标定的相机2

        self.conf = Nothing()
        self.conf.root_path = self.root_path
        self.conf.information_csv_path = os.path.join(self.root_path, 'user_info.csv')  # 存放用户信息的路径
        self.conf.current_NO = self.current_NO
        self.conf.current_ID = self.current_ID
        self.conf.current_sex = self.current_sex
        self.utils = Utils(self.conf)  # 工具类

        '''
        RGB图像显示界面
        '''
        #注册用户
        self.ui.pushButton_regist.clicked.connect(self.regist)
        #删除用户
        self.ui.pushButton_del.clicked.connect(self.del_user)
        #
        #5、RGB_1的thread
        self.RGB_1_th = RGB_1_Thread(self)
        self.RGB_1_th.signal_changeFrame.connect(self.atfn_RGB_changeFrame)
        #RGB1最为主相机独有的
        self.RGB_1_th.signal_label_statu.connect(self.signal_label_statu_process)
        self.RGB_1_th.signal_recordProgress.connect(self.atfn_update_recordProgress)
        self.RGB_1_th.signal_check_compelet.connect(self.check_compelet)
        self.RGB_1_th.start()
        #
        #6、RGB_2的thread
        self.RGB_2_th = RGB_2_Thread(self)
        self.RGB_2_th.signal_changeFrame.connect(self.atfn_RGB_changeFrame)
        self.RGB_2_th.start()

        '''
        深度图像显示界面
        '''

        '''
        相机标定界面
        '''
        self.ui.comboBox_calibration_camera_1.currentIndexChanged.connect(self.calibration_camera_1_changed)
        self.ui.comboBox_calibration_camera_2.currentIndexChanged.connect(self.calibration_camera_2_changed)
        #开始标定按钮
        self.ui.pushButton_start_calibration.clicked.connect(self.start_calibration)

        '''
        设置界面
        '''
        self.ui.lineEdit_sample_frame.textChanged.connect(self.sample_frame_changed)
        self.ui.lineEdit_FPS.textChanged.connect(self.FPS_changed)
        self.ui.lineEdit_total_recording_time.textChanged.connect(self.total_recording_time_changed)
        #路径选择
        self.ui.pushButton_select_path.clicked.connect(self.select_path)



if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())