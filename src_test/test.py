# -*- coding: utf-8 -*-
# @Author  : Wanglu
# @Time    : 2021/07/02 17:25

import datetime
import time, os, shutil
import numpy as np


##  获得当前时间
# now=datetime.datetime.now() #2019-04-11 14:18:41.629019
# print(now)

# for i in range(3):
#     time.sleep(0.1)
#     time = time.time()
#     print(time.time())
if __name__ == '__main__':

    # root_path = '../data'
    # RGBD_1_ts = np.load("D:/pycharm/gesture/手势估计项目/pic_collect/data/sample_00001/temp/RGBD_01_time_stamp.npy")
    # RGBD_2_ts = np.load("D:/pycharm/gesture/手势估计项目/pic_collect/data/sample_00001/temp/RGBD_02_time_stamp.npy")
    #
    # merge = {}
    # num_camera = 2
    #
    # for i in range(125):
    #     RGB_1_index = 'RGBD_01_%03d' % (i + 1)
    #     RGB_2_index = 'RGBD_02_%03d' % (i + 1)
    #     merge[RGB_1_index] = RGBD_1_ts[i]
    #     merge[RGB_2_index] = RGBD_2_ts[i]
    #
    # merge = np.asarray(sorted(merge.items(), key=lambda e:e[1]))
    #
    # temp_list = []
    # result = []
    # time_cost = []
    # keys = merge[:, 0]
    #
    #
    # flag = [False, False]
    #
    # for index, key in enumerate(keys):
    #     if all(flag):
    #         flag = [False] * num_camera
    #         temp_list = []
    #
    #         time_delay = np.asarray([float(merge[index - num_camera, 1]), float(merge[index - 1, 1])])
    #         time_cost.append(np.sum(abs(time_delay - time_delay[0])))
    #
    #         result.append(np.asarray([merge[index - num_camera, 0], merge[index - 1, 0]]))
    #
    #     camera = int(key.split('_')[1]) - 1
    #     if not flag[camera]:
    #         flag[camera] = True
    #     else:
    #         temp_list = []
    #     temp_list.append(merge[index])
    #
    # time_cost = np.asarray(time_cost)
    # sort_index = time_cost.argsort()[:100]
    # sort_index = sorted(sort_index)
    #
    # # 保存
    # sample_RGBD01_path = os.path.join(root_path, "sample_" + "00001", "RGBD_01")
    # os.makedirs(sample_RGBD01_path, exist_ok=True)
    # sample_RGBD02_path = os.path.join(root_path, "sample_" + "00001", "RGBD_02")
    # os.makedirs(sample_RGBD02_path, exist_ok=True)
    # sample_temp_path = os.path.join(root_path, "sample_" + "00001", "temp")
    #
    # sample_path = [sample_RGBD01_path, sample_RGBD02_path, sample_temp_path]
    #
    # for loop, index in enumerate(sort_index):
    #     pic_group = result[index]
    #     for i in range(num_camera):
    #         for pic in pic_group:
    #             camera_index = int(pic.split('_')[1])
    #             shutil.copy(os.path.join(sample_path[num_camera], pic + '.jpg'),
    #                         os.path.join(sample_path[camera_index - 1], '%03d.jpg' % (loop)))
    #
    # shutil.rmtree(sample_temp_path)
    # print(np.mean(time_cost[np.asarray(sort_index)]) * 1000)

    import cv2
    import numpy as np

    cap = cv2.VideoCapture(1)
    while (1):
        # get a frame
        ret, frame = cap.read()
        # show a frame
        cv2.imshow("capture", frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    cap.release()
    cv2.destroyAllWindows()
