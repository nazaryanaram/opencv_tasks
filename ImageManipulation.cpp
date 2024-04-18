#include <iostream>
#include <opencv2/opencv.hpp> 

void resize_image(cv::Mat& inputImage, cv::Mat& outputImage, int sizeX, int sizeY);
void flip_image(cv::Mat& inputImage, cv::Mat& outputImage, int select);
void crop_image(cv::Mat& inputImage, cv::Mat& outputImage, int x, int y, int width, int height);
void rotate_image(cv::Mat& inputImage, cv::Mat& outputImage, double radius);
bool save_image(cv::Mat& image, const std::string& fileName);


int main() {
    cv::Mat resizeImg;
    cv::Mat flipVertical;
    cv::Mat flipHorizontal;
    cv::Mat cropImage;
    cv::Mat rotateImage;

    std::string resizeFileName = "resized_image.jpg";
    std::string flipFileName = "flip_image.jpg";
    std::string cropFileName = "crop_image.jpg";
    std::string rotateFileName = "rotate_image.jpg";

    cv::Mat image = cv::imread("image.jpg", -1);
    if( image.empty()) {
        return -1;
    } 

    resize_image(image, resizeImg, 300, 500);
    cv::imshow("resized image", resizeImg);
    save_image(resizeImg, resizeFileName);

    flip_image(image, flipVertical, 0);
    cv::imshow("fliped Image", flipVertical);
    save_image(flipVertical, flipFileName);

    crop_image(image, cropImage, 100, 80, 300, 300);
    cv::imshow("croped image", cropImage);
    save_image(cropImage, cropFileName);

    rotate_image(image, rotateImage, 45);
    cv::imshow("rotate image", rotateImage);
    save_image(rotateImage, rotateFileName);
    cv::waitKey(0);
    return 0;
}

void resize_image(cv::Mat& inputImage, cv::Mat& outputImage, int sizeX, int sizeY) 
{
    cv::resize(inputImage, outputImage, cv::Size(sizeX, sizeY));
}

void flip_image(cv::Mat& inputImage, cv::Mat& outputImage, int select) 
{
    if (select) {
        cv::flip(inputImage, outputImage, 1);
    } else {
        cv::flip(inputImage, outputImage, 0);
    }
}

void crop_image(cv::Mat& inputImage, cv::Mat& outputImage, int x, int y, int width, int height) 
{
    cv::Rect roiRect(x, y, width, height);
    outputImage = inputImage(roiRect).clone();
}

void rotate_image(cv::Mat& inputImage, cv::Mat& outputImage, double radius)
{
    double angleRadians = radius * CV_PI / 180.0;
    cv::Point2f center(static_cast<float>(inputImage.cols) / 2, static_cast<float>(inputImage.rows) / 2);

    cv::Mat rotationMatrix = getRotationMatrix2D(center, radius, 1.0);
    cv::warpAffine(inputImage, outputImage, rotationMatrix, inputImage.size(), cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar());
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