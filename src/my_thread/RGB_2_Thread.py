# -*- coding: utf-8 -*-
# @Author  : Wanglu
# @Time    : 2021/06/25 10:50

from PyQt5.QtCore import QThread, pyqtSignal
import cv2
import time

class RGB_2_Thread(QThread):
    signal_changeFrame = pyqtSignal(list)

    def __init__(self, win):
        super(RGB_2_Thread, self).__init__()
        self.cap = cv2.VideoCapture(win.camera_RBGD_2_idx)  # 打开摄像头
        self.cap.set(cv2.CAP_PROP_FPS, 25)  # 设定帧率
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, win.CAP_PROP_FRAME_HEIGHT)  # 设定高度
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, win.CAP_PROP_FRAME_WIDTH)  # 设定宽度

        # 计算crop
        self.cap_img_height = int(self.cap.get(cv2.CAP_PROP_FRAME_HEIGHT))  # 采集图片的HEIGHT
        self.cap_img_width = int(self.cap.get(cv2.CAP_PROP_FRAME_WIDTH))  # 采集图片的WIDTH
        tmp = int((self.cap_img_width - self.cap_img_height) / 2)
        self.crop = [tmp, 0, tmp + self.cap_img_height, self.cap_img_height]
        self.win = win

    def run(self):
        while(1):
            ret, color = self.cap.read()
            color = color[self.crop[1]:self.crop[3], self.crop[0]:self.crop[2], :]
            self.signal_changeFrame.emit([color, self.win.ui.label_RGB_2])