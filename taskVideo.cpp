#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat  = cv::imread("input.jpg", -1);
    if (image.empty()) {
        std::cout << "Error: Could not open or find the image." << std::endl;
        return -1;
    }
    cv::namedWindow("AI Surveillance", cv::WINDOW_NORMAL);
    cv::imshow("AI Surveillance", image); 
    cv::waitKey(0);
    cv::destroyWindow("AI Surveillance");
    return 0;
}
