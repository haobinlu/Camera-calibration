# -*- coding: utf-8 -*-
# @Author  : Wanglu
# @Time    : 2021/07/02 17:25
import numpy as np
from cv2 import cv2 as cv

img_rgb = "1633141633922.jpg"

R = np.eye(3)
img_size = (1280, 960)
camera_matrix = np.array([718.3016461675478, 0, 639.4761478494999, 0, 718.9502993821736, 451.8233122909601, 0, 0, 1, ]).reshape([3, 3])
distortion_coefficients = np.array([-0.08092601493333926, -0.007729829738556227, -0.0809847001415104, 0.14535420352449413]).reshape([4, 1])
mapx, mapy = cv.fisheye.initUndistortRectifyMap(camera_matrix, distortion_coefficients, R, camera_matrix, img_size,
                                                cv.CV_32FC1)
srcImg = cv.imread(img_rgb)
# srcImg = cv.imread("camera.bmp")
resultImg = cv.remap(srcImg, mapx, mapy, cv.INTER_LINEAR, cv.BORDER_CONSTANT)
cv.imwrite("result_1.png", resultImg)