#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

void show_video(cv::VideoCapture cap);

int main() {
    cv::VideoCapture cap;
    cap.open("video.mov");
    show_video(cap);
    return 0;
}

void show_video(cv::VideoCapture cap)
{
    cv::namedWindow("AISurveillance", cv::WINDOW_AUTOSIZE);
    cv::Mat frame;
    while(1) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        cv::imshow("AISurveillance", frame);
        if( cv::waitKey(33) >= 0 ) break;
    }
}




