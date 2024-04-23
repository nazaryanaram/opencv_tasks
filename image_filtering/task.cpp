#include <iostream>
#include <opencv2/opencv.hpp>

void bluredImage(cv::Mat& input, cv::Mat& output);
void sharpedFilter(cv::Mat& input, cv::Mat& output);
void medianBlurFilter(cv::Mat& input, cv::Mat& output);
bool save_image(cv::Mat& image, const std::string& fileName);

int main()
{
    std::string fileLAB = "fileLab.png";
    std::string fileHSV = "fileHSV.png";
    std::string fileRGB = "fileRGB.png";
    std::string fileGRAY = "fileGRAY.png";
    std::string fileBlur = "fileblur.png";
    std::string fileMedian = "filemedian.png";
    std::string fileSharped = "filesharped.png";
    cv::Mat image = cv::imread("image.jpg", -1);
    cv::Mat imageLAB, imageRGB, imageHSV, imageGRAY, blurImage, medianImage, sharpedImage;
    if (image.empty()) {
        std::cout << "Image is empty" << std::endl;
        return -1;
    }

    cv::cvtColor(image, imageHSV, cv::COLOR_BGR2HSV);
    cv::cvtColor(image, imageLAB, cv::COLOR_BGR2Lab);
    cv::cvtColor(image, imageRGB, cv::COLOR_BGR2RGB);
    cv::cvtColor(image, imageGRAY, cv::COLOR_BGR2GRAY);

    cv::imshow("HSV space", imageHSV);
    cv::imshow("LAB space", imageLAB);
    cv::imshow("RGB space", imageRGB);
    cv::imshow("GRAY space", imageGRAY);
    
    bluredImage(image, blurImage);
    cv::imshow("Gaussian blur", blurImage);
    sharpedFilter(image, sharpedImage);
    cv::imshow("Sharped filter", sharpedImage);
    medianBlurFilter(image, medianImage);
    cv::imshow("Median filter", medianImage);

    save_image(imageHSV, fileHSV);
    save_image(imageLAB, fileLAB);
    save_image(imageRGB, fileRGB);
    save_image(imageGRAY, fileGRAY);
    save_image(blurImage, fileBlur);
    save_image(sharpedImage, fileSharped);
    save_image(medianImage, fileMedian);
    cv::waitKey(0);
}

void bluredImage(cv::Mat& input, cv::Mat& output)
{
    cv::Size kernel(5, 5);
    double x = 0;
    double y = 0;
    cv::GaussianBlur(input, output, kernel, x, y);
}

void sharpedFilter(cv::Mat& input, cv::Mat& output)
{
    cv::Mat kernel = (cv::Mat_<float>(3, 3) <<
        0, -1, 0,
        -1, 5, -1,
        0, -1, 0);
    cv::Mat sharpenedImage;
    cv::filter2D(input, output, input.depth(), kernel);
}

void medianBlurFilter(cv::Mat& input, cv::Mat& output)
{
    int kernel = 15;
    cv::medianBlur(input, output, kernel);
}

bool save_image(cv::Mat& image, const std::string& fileName)
{
    if (image.empty()) {
        std::cerr << "Image is empty failed Saving" << std::endl;
        return false;
    }

    try {
        cv::imwrite(fileName, image);
        std::cout << "Image saved successfuly" << std::endl;
        return true;
    } catch(const cv::Exception& signal) {
        std::cerr << "Error: " << signal.what() << std::endl;
        return false;
    }
}
