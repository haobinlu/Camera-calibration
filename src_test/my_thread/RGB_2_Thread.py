# -*- coding: utf-8 -*-
# @Author  : Wanglu
# @Time    : 2021/06/25 10:50

from PyQt5.QtCore import QThread, pyqtSignal
import cv2, queue, threading, time
from datetime import datetime

class RGB_2_Thread(QThread):
    signal_changeFrame = pyqtSignal(list)

    def __init__(self, win):
        super(RGB_2_Thread, self).__init__()

        self.win = win
        self.cap = cv2.VideoCapture(win.camera_RBGD_2_idx)  # 打开摄像头
        self.cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc('M', 'J', 'P', 'G'))
        self.cap.set(cv2.CAP_PROP_FPS, self.win.FPS)  # 设定帧率
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, win.CAP_PROP_FRAME_HEIGHT)  # 设定高度
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, win.CAP_PROP_FRAME_WIDTH)  # 设定宽度

        self.sample_frame = win.sample_frame  # 采集采集多少帧（注册）

        #运行状态[0：无动作, 1：注册, 2:标定]
        self.recording = 0
        self.compelet = True
        self.ready_time = 0
        self.total_ready_time = win.total_ready_time

        self.imgs_buffer = {}

    def run(self):
        jj = 0
        while(1):
            self.cap.grab()
            ret, color = self.cap.retrieve()

            self.signal_changeFrame.emit([color, self.win.ui.label_RGB_2])
            if self.recording == 1:
                now_time = time.time()
                print("tread2:{}:{}".format(jj, now_time))
                jj += 1

                self.compelet = False

                # # 白跑一次进度条，用户做准备
                # if self.ready_time < self.total_ready_time:
                #     self.ready_time += 1
                #     self.signal_recordProgress.emit(int(self.ready_time * 100 / self.total_ready_time))  # 更新进度条
                #     continue

                self.imgs_buffer[str(now_time)] = color


                if len(self.imgs_buffer) == self.sample_frame:
                    # print("{}:{}   RGB2结束第{}次录制".format(datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3], self.win.current_NO, self.r_t))
                    print('tread2:{}'.format(datetime.now()))
                    self.win.utils.save_video('RGBD_02', self.imgs_buffer, 'rgb')
                    self.ready_time = 0
                    self.imgs_buffer = {}

                    jj = 0
                    self.compelet = True
                    self.recording = 0
