#include <cstdlib>
#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>

int main() {
    std::vector<cv::Rect> features;
    cv::CascadeClassifier classifier("haarcascade_frontalface_alt.xml");
    const char* window_name{"Facial Recognition Window"};
    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

    // device camera
    cv::VideoCapture capture(0); 
    if (not capture.isOpened()) {
       std::cerr << "cannot open video capture device\n";
       std::exit(EXIT_FAILURE);
    }

    cv::Mat image;
    cv::Mat grayscale_image;
    while (true) {
        capture >> image;
        cv::cvtColor(image, grayscale_image, cv::COLOR_BGR2GRAY);
        cv::equalizeHist(grayscale_image, grayscale_image);
        classifier.detectMultiScale(grayscale_image, features, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
         // draw  rectangle each features
         for (auto&& feature : features) {
            cv::rectangle(image, feature, cv::Scalar(0, 0, 255), 7);
         }
        cv::imshow(window_name, image);

        // end program 
         switch (cv::waitKey(10)) {
          case 'q':
            std::exit(EXIT_SUCCESS);
         case 'Q':
            std::exit(EXIT_SUCCESS);
            default:
            break;
        }
    }
    return EXIT_SUCCESS;
}
