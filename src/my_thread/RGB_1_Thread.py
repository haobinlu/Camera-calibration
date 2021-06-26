# -*- coding: utf-8 -*-
# @Author  : Wanglu
# @Time    : 2021/06/24 11:35

from PyQt5.QtCore import QThread, pyqtSignal
import cv2, time
from datetime import datetime

class RGB_1_Thread(QThread):
    signal_changeFrame = pyqtSignal(list)

    signal_label_statu = pyqtSignal(list)
    signal_recordProgress = pyqtSignal(int)
    signal_check_compelet = pyqtSignal(bool)

    def __init__(self, win):
        super(RGB_1_Thread, self).__init__()
        self.win = win

        self.cap = cv2.VideoCapture(win.camera_RBGD_1_idx)  # 打开摄像头
        self.cap.set(cv2.CAP_PROP_FPS, self.win.FPS)  # 设定帧率
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, win.CAP_PROP_FRAME_HEIGHT)  # 设定高度
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, win.CAP_PROP_FRAME_WIDTH)  # 设定宽度
        self.sample_frame = win.sample_frame  # 采集采集多少帧（注册）

        # 计算crop
        self.cap_img_height = int(self.cap.get(cv2.CAP_PROP_FRAME_HEIGHT))  # 采集图片的HEIGHT
        self.cap_img_width = int(self.cap.get(cv2.CAP_PROP_FRAME_WIDTH))  # 采集图片的WIDTH
        tmp = int((self.cap_img_width - self.cap_img_height) / 2)
        self.crop = [tmp, 0, tmp + self.cap_img_height, self.cap_img_height]
        self.win = win

        self.r_t = 0 #已经注册的次数

        #运行状态[0：无动作, 1：注册]
        self.recording = False
        self.compelet = True
        self.ready_time = 0
        self.total_ready_time = win.total_ready_time

        self.imgs_buffer = []

    def run(self):
        while(1):
            ret, color = self.cap.read()
            color = color[self.crop[1]:self.crop[3], self.crop[0]:self.crop[2], :]
            self.signal_changeFrame.emit([color, self.win.ui.label_RGB_1])

            if self.recording:
                if len(self.imgs_buffer) == 0:
                    print("{}:{}   RGB1开始第{}次录制".format(datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3], self.win.current_NO, self.r_t))

                self.compelet = False
                self.signal_label_statu.emit(['red', None, self.r_t])

                # # 白跑一次进度条，用户做准备
                # if self.ready_time < self.total_ready_time:
                #     self.ready_time += 1
                #     self.signal_recordProgress.emit(int(self.ready_time * 100 / self.total_ready_time))  # 更新进度条
                #     continue

                self.imgs_buffer.append(color)
                # self.signal_recordProgress.emit(int(len(self.imgs_buffer) * 100 / self.sample_frame))  # 更新进度条

                if len(self.imgs_buffer) == self.sample_frame:
                    print("{}:{}   RGB1结束第{}次录制".format(datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3], self.win.current_NO, self.r_t))
                    self.win.utils.save_video(self.r_t + 1, 'RGBD_01', self.imgs_buffer, 'rgb')
                    self.r_t +=1
                    self.ready_time = 0
                    self.imgs_buffer = []

                    if self.r_t == self.win.total_recording_time:
                        self.r_t = 0
                        self.win.utils.add_id()
                        self.compelet = True
                        self.recording = False
                        time.sleep(0.1)
                        self.signal_check_compelet.emit(True)