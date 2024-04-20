#include <iostream>
#include <opencv2/opencv.hpp>

void show_video(cv::VideoCapture cap);
void show_vertical_video(cv::VideoCapture cap);
void show_horizontal_video(cv::VideoCapture cap);
void show_rotate_video(cv::VideoCapture cap);
void show_grayscale_video(cv::VideoCapture cap);
void show_hsv_video(cv::VideoCapture cap);
void show_lab_video(cv::VideoCapture cap);
void show_blur_video(cv::VideoCapture cap);
void show_median_video(cv::VideoCapture cap);
void draw_rectangle_in_video(cv::VideoCapture cap);
void rotate_image(cv::Mat& inputImage, cv::Mat& outputImage, double radius);
void select(cv::VideoCapture cap);
void draw_options(cv::Mat& frame);
void show_current_time(cv::Mat& frame);

int main()
{
    cv::VideoCapture cap(0);
    show_video(cap);   
}

void show_horizontal_video(cv::VideoCapture cap)
{
    cv::Mat frame;
    cv::Mat flipFrame;
    while(true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        cv::flip(frame, flipFrame, 1);
        draw_options(flipFrame);
        show_current_time(flipFrame);
        cv::putText(flipFrame, "HORIZONTAL FLIP MODE", cv::Point(10, 50), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 0));
        cv::imshow("MAINWINDOW", flipFrame);
        select(cap);
    }
}

void show_vertical_video(cv::VideoCapture cap)
{
    cv::Mat frame;
    cv::Mat flipFrame;
    while(true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        cv::flip(frame, flipFrame, 0); 
        draw_options(flipFrame);
        show_current_time(flipFrame);
        cv::putText(flipFrame, "VERTICAL FLIP MODE", cv::Point(10, 50), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 0));
        cv::imshow("MAINWINDOW", flipFrame);
        select(cap);
    }
}

void show_rotate_video(cv::VideoCapture cap)
{
    cv::Mat frame;
    cv::Mat rotateFrame;
    while(true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        rotate_image(frame, rotateFrame, 45);
        draw_options(rotateFrame);
        show_current_time(rotateFrame);
        cv::putText(rotateFrame, "ROTATE MODE", cv::Point(10, 50), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 0));
        cv::imshow("MAINWINDOW", rotateFrame);
        select(cap);
    }
}

void show_grayscale_video(cv::VideoCapture cap)
{
    cv::Mat frame;
    cv::Mat grayFrame;
    while(true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);
        draw_options(grayFrame);
        show_current_time(grayFrame);
        cv::putText(grayFrame, "GRAYSCALE MODE", cv::Point(10, 50), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 0));
        cv::imshow("MAINWINDOW", grayFrame);
        select(cap);
    }
}

void show_hsv_video(cv::VideoCapture cap)
{
    cv::Mat frame;
    cv::Mat hsvFrame;
    while(true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        cv::cvtColor(frame, hsvFrame, cv::COLOR_BGR2HSV);
        draw_options(hsvFrame);
        show_current_time(hsvFrame);
        cv::putText(hsvFrame, "GRAYSCALE MODE", cv::Point(10, 50), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 0));
        cv::imshow("MAINWINDOW", hsvFrame);
        select(cap);
    }
}

void show_lab_video(cv::VideoCapture cap)
{
    cv::Mat frame;
    cv::Mat labFrame;
    while(true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        cv::cvtColor(frame, labFrame, cv::COLOR_BGR2Lab);
        draw_options(labFrame);
        show_current_time(labFrame);
        cv::putText(labFrame, "LAB MODE", cv::Point(10, 50), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 0));
        cv::imshow("MAINWINDOW", labFrame);
        select(cap);
    }
}

void show_blur_video(cv::VideoCapture cap)
{
    cv::Size kernelSize(15, 15);
    cv::Mat frame;
    cv::Mat blurFrame;
    while(true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        cv::blur(frame, blurFrame, kernelSize);
        draw_options(blurFrame);
        show_current_time(blurFrame);
        cv::putText(blurFrame, "BLUR MODE", cv::Point(10, 50), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 0));
        cv::imshow("MAINWINDOW", blurFrame);
        select(cap);
    }
}

void show_median_video(cv::VideoCapture cap)
{
    int kernel = 15;
    cv::Mat frame;
    cv::Mat medianFrame;
    while(true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        cv::medianBlur(frame, medianFrame, kernel);
        draw_options(medianFrame);
        show_current_time(medianFrame);
        cv::putText(medianFrame, "MEDIAN MODE", cv::Point(10, 50), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 0));
        cv::imshow("MAINWINDOW", medianFrame);
        select(cap);
    }
}

void draw_rectangle_in_video(cv::VideoCapture cap)
{
    cv::Point start_point(500, 115);
    cv::Point end_point(800, 225);
    cv::Mat frame;
    while(true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        draw_options(frame);
        show_current_time(frame);
        cv::putText(frame, "DRAW RECTANGLE MODE", cv::Point(10, 50), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 0));
        cv::rectangle(frame, start_point, end_point, cv::Scalar(0, 0, 255), 3, 8, 0);
        cv::imshow("MAINWINDOW", frame);
        select(cap);
    }
}

void show_video(cv::VideoCapture cap)
{
    cv::Mat frame;
    while(true) {
        cap >> frame;
        if(frame.empty()) {
            break;
        }
        draw_options(frame);
        show_current_time(frame);
        cv::putText(frame, "NORMAL MODE", cv::Point(10, 50), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 0));
        cv::imshow("MAINWINDOW", frame);
        select(cap);
    }
    return;
}

void select(cv::VideoCapture cap)
{
   switch(cv::waitKey(33))
   {
        case 'q':
            exit(1);
            break;
        case 'v':
            show_vertical_video(cap);
            break;
        case 'h':
            show_horizontal_video(cap);
            break;
        case 'r':
            show_rotate_video(cap);
            break;
        case 'g':
            show_grayscale_video(cap);
            break;
        case 'l':
            show_lab_video(cap);
            break;
        case 's':
            show_hsv_video(cap);
            break;
        case 'b':
            show_blur_video(cap);
            break;
        case 'm':
            show_median_video(cap);
            break;
        case 'k':
            draw_rectangle_in_video(cap);
            break;
        case 'n':
            show_video(cap);
            break;
   }
}

void show_current_time(cv::Mat& frame)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::string current_time = asctime(ltm);
    current_time.erase(std::remove(current_time.begin(), current_time.end(), '\n'), current_time.end());
    cv::putText(frame, current_time, cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 255), 2);
}

void draw_options(cv::Mat& frame)
{
    cv::putText(frame, "KEY EVENTS", cv::Point(1000, 50), cv::FONT_HERSHEY_TRIPLEX, 1, cv::Scalar(250,225,100));
    cv::putText(frame, "'v' -> vertical", cv::Point(1000, 100), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0,250));
    cv::putText(frame, "'h' -> horizontal", cv::Point(1000, 130), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0,250));
    cv::putText(frame, "'r' -> rotate", cv::Point(1000, 160), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0,250));
    cv::putText(frame, "'g' -> grayScale", cv::Point(1000, 190), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 250));
    cv::putText(frame, "'l' -> lab space", cv::Point(1000, 220), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 250));
    cv::putText(frame, "'s' -> hsv space", cv::Point(1000, 250), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 250));
    cv::putText(frame, "'b' -> blur filter", cv::Point(1000, 280), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 250));
    cv::putText(frame, "'m' -> median filter", cv::Point(1000, 310), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 250));
    cv::putText(frame, "'k' -> draw rectangle", cv::Point(1000, 340), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 250));
    cv::putText(frame, "'n' -> normal video", cv::Point(1000, 370), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 250));
    cv::putText(frame, "'q' -> close camera", cv::Point(1000, 400), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.70, cv::Scalar(0, 0, 250));
}

void rotate_image(cv::Mat& inputImage, cv::Mat& outputImage, double radius)
{
    double angleRadians = radius * CV_PI / 180.0;
    cv::Point2f center(static_cast<float>(inputImage.cols) / 2, static_cast<float>(inputImage.rows) / 2);

    cv::Mat rotationMatrix = getRotationMatrix2D(center, radius, 1.0);
    cv::warpAffine(inputImage, outputImage, rotationMatrix, inputImage.size(), cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar());
}