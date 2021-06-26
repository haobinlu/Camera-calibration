# -*- coding: utf-8 -*-
# @Author  : Wanglu
# @Time    : 2021/06/26 9:49


import cv2

if __name__ == "__main__":
    webcam = cv2.VideoCapture(0)

    if not webcam.isOpened():
        print("can't open the camera!!!")

    webcam.set(3, 480)  # width=1920
    webcam.set(4, 480)  # height=1080
    webcam.set(cv2.CAP_PROP_FPS, 20)  # 设定帧率
    print(webcam.get(cv2.CAP_PROP_FPS))  # 设定帧率

    while True:
        ret, frame = webcam.read()
        cv2.imshow("video", frame)
        # Hit 'q' on the keyboard to quit!
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Release handle to the webcam
    webcam.release()
    cv2.destroyAllWindows()