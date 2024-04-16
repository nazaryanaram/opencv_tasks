#include <opencv2/opencv.hpp>


using namespace cv;
void show_video(cv::VideoCapture cap);

int main() {
    cv::VideoCapture cap(0);
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




