# -*- coding: utf-8 -*-
# @Author  : Wanglu
# @Time    : 2021/06/25 11:33
import datetime
import os
import csv

import cv2, time, shutil
import numpy as np
import pandas as pd



class Utils():
    def __init__(self, conf):
        self.conf = conf
        self.save_frame = conf.save_frame
        self.information_csv_path = conf.information_csv_path
        self.user_sample_num_ls = []
        self.ready_cache = []  # cache
        self.init_csv()

    def init_csv(self):
        # 检插特征库里和csv里是否一样
        if not os.path.exists(self.information_csv_path):
            headers = ['sample序号', 'id', '性别']
            with open(self.information_csv_path, 'w',  encoding='utf-8-sig')as f:
                f_csv = csv.writer(f)
                f_csv.writerow(headers)

        # 读csv
        with open(self.information_csv_path,  encoding='utf-8-sig') as f:
            f_csv = csv.reader(f)

            for i, row in enumerate(f_csv):
                if i == 0: continue
                try:
                    sample_number = row[0]
                    self.user_sample_num_ls.append(sample_number)
                except:
                    break

    def save_video(self, camera, imgs, mode):
        sample_path = os.path.join(self.conf.root_path, "sample_" + self.conf.current_NO)
        if not os.path.exists(sample_path):
            os.mkdir(sample_path)
        sample_path = os.path.join(sample_path, 'temp')
        if not os.path.exists(sample_path):
            os.mkdir(sample_path)
        stamp_ls = []
        for index, key in enumerate(imgs.keys()):
            img_path = os.path.join(sample_path, '%s_%03d.jpg' % (camera, index + 1))
            cv2.imwrite(img_path, imgs[key])
            stamp_ls.append(key)
        np.save(os.path.join(sample_path, camera + "_time_stamp.npy") ,stamp_ls)

    def alignment(self):
        merge = {}
        num_camera = 2

        sample_path = os.path.join(self.conf.root_path, "sample_" + self.conf.current_NO, "temp")
        RGBD_1_ts = np.load(os.path.join(sample_path, "RGBD_01_time_stamp.npy"))
        RGBD_2_ts = np.load(os.path.join(sample_path, "RGBD_02_time_stamp.npy"))

        for i in range(self.conf.sample_frame):
            RGB_1_index = 'RGBD_01_%03d' % (i + 1)
            RGB_2_index = 'RGBD_02_%03d' % (i + 1)
            merge[RGB_1_index] = RGBD_1_ts[i]
            merge[RGB_2_index] = RGBD_2_ts[i]

        merge = np.asarray(sorted(merge.items(), key=lambda e: e[1]))

        temp_list = []
        result = []
        time_cost = []
        keys = merge[:, 0]

        flag = [False] * num_camera

        for index, key in enumerate(keys):
            if all(flag):
                flag = [False] * num_camera
                temp_list = []

                time_delay = np.asarray([float(merge[index - num_camera, 1]), float(merge[index - 1, 1])])
                time_cost.append(np.sum(abs(time_delay - time_delay[0])))

                result.append(np.asarray([merge[index - num_camera, 0], merge[index - 1, 0]]))

            camera = int(key.split('_')[1]) - 1
            if not flag[camera]:
                flag[camera] = True
            else:
                temp_list = []
            temp_list.append(merge[index])

        time_cost = np.asarray(time_cost)
        if len(time_cost) < self.save_frame:
            return None
        sort_index = time_cost.argsort()[:self.save_frame]
        sort_index = sorted(sort_index)

        #保存
        sample_RGBD01_path = os.path.join(self.conf.root_path, "sample_" + self.conf.current_NO, "RGBD_01")
        os.makedirs(sample_RGBD01_path, exist_ok=True)
        sample_RGBD02_path = os.path.join(self.conf.root_path, "sample_" + self.conf.current_NO, "RGBD_02")
        os.makedirs(sample_RGBD02_path, exist_ok=True)
        sample_temp_path = os.path.join(self.conf.root_path, "sample_" + self.conf.current_NO, "temp")

        sample_path = [sample_RGBD01_path, sample_RGBD02_path, sample_temp_path]

        for loop, index in enumerate(sort_index):
            pic_group = result[index]
            for i in range(num_camera):
                for pic in pic_group:
                    camera_index = int(pic.split('_')[1])
                    shutil.copy(os.path.join(sample_path[num_camera], pic + '.jpg'), os.path.join(sample_path[camera_index - 1], '%03d.jpg' % (loop)))

        shutil.rmtree(sample_temp_path)
        return np.mean(time_cost[np.asarray(sort_index)]) * 1000


    def save_picture(self, camera, img):
        sample_path = os.path.join(self.conf.root_path, "calibration_pic", camera)
        if not os.path.exists(sample_path):
            os.mkdir(sample_path)
        img_path = os.path.join(sample_path, "{}.jpg".format(datetime.datetime.now().strftime('%m_%d_%H_%M_%S')))
        cv2.imwrite(img_path, img)

    def add_id(self):
        if self.conf.current_NO in self.user_sample_num_ls:
            return
        else:
            user_data = pd.read_csv(self.information_csv_path, dtype=str)
            new_item = {"sample序号": self.conf.current_NO, "id": self.conf.current_ID, "性别": self.conf.current_sex}
            user_data = user_data.append(new_item, ignore_index=True)
        user_data.to_csv(self.information_csv_path, index=None)
        self.user_sample_num_ls.append(self.conf.current_NO)
