import cv2
import numpy as np
import time

def show_video(cap):
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        
        draw_options(frame)
        show_current_time(frame)
        cv2.putText(frame, "NORMAL MODE", (10, 50), cv2.FONT_HERSHEY_COMPLEX_SMALL, 0.70, (0, 0, 0))
        cv2.imshow("MAINWINDOW", frame)
        
        key = cv2.waitKey(33)
        if key == ord('q'):
            break
        elif key == ord('v'):
            show_vertical_video(cap)
        elif key == ord('h'):
            show_horizontal_video(cap)
        elif key == ord('r'):
            show_rotate_video(cap)
        elif key == ord('g'):
            show_grayscale_video(cap)
        elif key == ord('l'):
            show_lab_video(cap)
        elif key == ord('s'):
            show_hsv_video(cap)
        elif key == ord('b'):
            show_blur_video(cap)
        elif key == ord('m'):
            show_median_video(cap)
        elif key == ord('k'):
            draw_rectangle_in_video(cap)

def show_horizontal_video(cap):
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        
        flip_frame = cv2.flip(frame, 1)
        draw_options(flip_frame)
        show_current_time(flip_frame)
        cv2.putText(flip_frame, "HORIZONTAL FLIP MODE", (10, 50), cv2.FONT_HERSHEY_COMPLEX_SMALL, 0.70, (0, 0, 0))
        cv2.imshow("MAINWINDOW", flip_frame)
        
        key = cv2.waitKey(33)
        if key == ord('q'):
            break

def show_vertical_video(cap):
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        
        flip_frame = cv2.flip(frame, 0)
        draw_options(flip_frame)
        show_current_time(flip_frame)
        cv2.putText(flip_frame, "VERTICAL FLIP MODE", (10, 50), cv2.FONT_HERSHEY_COMPLEX_SMALL, 0.70, (0, 0, 0))
        cv2.imshow("MAINWINDOW", flip_frame)
        
        key = cv2.waitKey(33)
        if key == ord('q'):
            break

def show_rotate_video(cap):
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        
        rotate_frame = rotate_image(frame, 45)
        draw_options(rotate_frame)
        show_current_time(rotate_frame)
        cv2.putText(rotate_frame, "ROTATE MODE", (10, 50), cv2.FONT_HERSHEY_COMPLEX_SMALL, 0.70, (0, 0, 0))
        cv2.imshow("MAINWINDOW", rotate_frame)
        
        key = cv2.waitKey(33)
        if key == ord('q'):
            break

def show_grayscale_video(cap):
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        
        gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        draw_options(gray_frame)
        show_current_time(gray_frame)
        cv2.putText(gray_frame, "GRAYSCALE MODE", (10, 50), cv2.FONT_HERSHEY_COMPLEX_SMALL, 0.70, (0, 0, 0))
        cv2.imshow("MAINWINDOW", gray_frame)
        
        key = cv2.waitKey(33)
        if key == ord('q'):
            break

def show_hsv_video(cap):
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        
        hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        draw_options(hsv_frame)
        show_current_time(hsv_frame)
        cv2.putText(hsv_frame, "HSV MODE", (10, 50), cv2.FONT_HERSHEY_COMPLEX_SMALL, 0.70, (0, 0, 0))
        cv2.imshow("MAINWINDOW", hsv_frame)
        
        key = cv2.waitKey(33)
        if key == ord('q'):
            break

def show_lab_video(cap):
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        
        lab_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2Lab)
        draw_options(lab_frame)
        show_current_time(lab_frame)
        cv2.putText(lab_frame, "LAB MODE", (10, 50), cv2.FONT_HERSHEY_COMPLEX_SMALL, 0.70, (0, 0, 0))
        cv2.imshow("MAINWINDOW", lab_frame)
        
        key = cv2.waitKey(33)
        if key == ord('q'):
            break

def show_blur_video(cap):
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        
        blur_frame = cv2.blur(frame, (15, 15))
        draw_options(blur_frame)
        show_current_time(blur_frame)
        cv2.putText(blur_frame, "BLUR MODE", (10, 50), cv2.FONT_HERSHEY_COMPLEX_SMALL, 0.70, (0, 0, 0))
        cv2.imshow("MAINWINDOW", blur_frame)
        
        key = cv2.waitKey(33)
        if key == ord('q'):
            break

def show_median_video(cap):
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        
        median_frame = cv2.medianBlur(frame, 15)
        draw_options(median_frame)
        show_current_time(median_frame)
        cv2.putText(median_frame, "MEDIAN MODE", (10, 50), cv2.FONT_HERSHEY_COMPLEX_SMALL, 0.70, (0, 0, 0))
        cv2.imshow("MAINWINDOW", median_frame)
        
        key = cv2.waitKey(33)
        if key == ord('q'):
            break

def draw_rectangle_in_video(cap):
    start_point = (500, 115)
    end_point = (800, 225)
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        
        draw_options(frame)
        show_current_time(frame)
        cv2.putText(frame, "DRAW RECTANGLE MODE", (10, 50), cv2.FONT_HERSHEY_COMPLEX_SMALL, 0.70, (0, 0, 0))
        cv2.rectangle(frame, start_point, end_point, (0, 0, 255), 3)
        cv2.imshow("MAINWINDOW", frame)
        
        key = cv2.waitKey(33)
        if key == ord('q'):
            break

def rotate_image(input_image, angle):
    angle_radians = angle * np.pi / 180.0
    center = (input_image.shape[1] / 2, input_image.shape[0] / 2)
    rotation_matrix = cv2.getRotationMatrix2D(center, angle, 1.0)
    rotated_image = cv2.warpAffine(input_image, rotation_matrix, (input_image.shape[1], input_image.shape[0]))
    return rotated_image

def draw_options(frame):
    cv2.putText(frame, "KEY EVENTS", (1000, 50), cv2.FONT_HERSHEY_TRIPLEX, 1, (250, 225, 100))
    key_options = [
        ("'v' -> vertical", 100),
        ("'h' -> horizontal", 130),
        ("'r' -> rotate", 160),
        ("'g' -> grayScale", 190),
        ("'l' -> lab space", 220),
        ("'s' -> hsv space", 250),
        ("'b' -> blur filter", 280),
        ("'m' -> median filter", 310),
        ("'k' -> draw rectangle", 340),
        ("'n' -> normal video", 370),
        ("'q' -> close camera", 400)
    ]
    for text, y in key_options:
        cv2.putText(frame, text, (1000, y), cv2.FONT_HERSHEY_COMPLEX_SMALL, 0.70, (0, 0, 250))

def show_current_time(frame):
    current_time = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
    cv2.putText(frame, current_time, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 255), 2)

if __name__ == "__main__":
    cap = cv2.VideoCapture(0)
    cv2.namedWindow("MAINWINDOW", cv2.WINDOW_NORMAL)
    show_video(cap)
    cap.release()
    cv2.destroyAllWindows()
