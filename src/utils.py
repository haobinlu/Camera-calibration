# -*- coding: utf-8 -*-
# @Author  : Wanglu
# @Time    : 2021/06/25 11:33

import os
import csv

import cv2
import numpy as np
import pandas as pd


class Utils():
    def __init__(self, conf):
        self.conf = conf
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

    def save_video(self, r_t, camera, imgs, mode):
        sample_path = os.path.join(self.conf.root_path, "sample_" + self.conf.current_NO)
        if not os.path.exists(sample_path):
            os.mkdir(sample_path)
        sample_path = os.path.join(sample_path, str(r_t))
        if not os.path.exists(sample_path):
            os.mkdir(sample_path)
        sample_path = os.path.join(sample_path, camera)
        if not os.path.exists(sample_path):
            os.mkdir(sample_path)
        for index, img in enumerate(imgs):
            img_path = os.path.join(sample_path, mode + '_%03d.jpg' % (index + 1))
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
