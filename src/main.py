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
import os
os.environ["KMP_DUPLICATE_LIB_OK"]  =  "TRUE"

from ui.main_UI import Ui_MainWindow
from src.my_thread.RGB_1_Thread import RGB_1_Thread
from src.my_thread.RGB_2_Thread import RGB_2_Thread

class MainWindow(QtWidgets.QMainWindow):
    def atfn_RGB_changeFrame(self, lst):  # lst第一位为图片cv2的BGR图片, 第二位为字符串mode
        img, pos= lst[0], lst[1]
        img = cv2.flip(img, 1)
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        img = cv2.resize(img, (self.label_RGB_height, self.label_RGB_width))
        img = QImage(img, self.label_RGB_height, self.label_RGB_width, QImage.Format_RGB888)
        img = QPixmap.fromImage(img)
        pos.setPixmap(img)

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

        #测试用
        self.camera_RBGD_1_idx = 0  # RGBF相机1 idx
        self.camera_RBGD_2_idx = 1  # RGBF相机1 idx

        self.CAP_PROP_FRAME_HEIGHT = 480  # 采集图片的HEIGHT
        self.CAP_PROP_FRAME_WIDTH = 640  # 采集图片的WIDTH

        self.label_RGB_height = self.ui.label_RGB_1.geometry().height()  # 图像显示位置的高度
        self.label_RGB_width = self.ui.label_RGB_1.geometry().width()

        #5、RGB_1的thread
        self.RGB_1_th = RGB_1_Thread(self)
        self.RGB_1_th.signal_changeFrame.connect(self.atfn_RGB_changeFrame)
        self.RGB_1_th.start()

        #6、RGB_2的thread
        self.RGB_2_th = RGB_2_Thread(self)
        self.RGB_2_th.signal_changeFrame.connect(self.atfn_RGB_changeFrame)
        self.RGB_2_th.start()


if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())