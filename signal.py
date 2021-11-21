# -*- coding: utf-8 -*-
# @Author  : Wanglu
# @Time    : 2021/07/31 8:53
from serial import Serial
import cv2, time

if __name__ == '__main__':
    with Serial('COM3', 9600) as ser:
        time.sleep(1)
        print('begin')
        while True:
            # print('trig')
            ser.write(b'\xfe')
            ser.flush()
            #cv2.waitKey(30)
            time.sleep(0.067)