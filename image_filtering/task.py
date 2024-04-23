import cv2

def blured_image(input_image):
    kernel_size = (5, 5)
    blurred_image = cv2.GaussianBlur(input_image, kernel_size, 0)
    return blurred_image

def sharped_filter(input_image):
    kernel = np.array([
        [0, -1, 0],
        [-1, 5, -1],
        [0, -1, 0]
    ], dtype=np.float32)
    sharpened_image = cv2.filter2D(input_image, -1, kernel)
    return sharpened_image

def median_blur_filter(input_image):
    kernel_size = 15
    median_blurred_image = cv2.medianBlur(input_image, kernel_size)
    return median_blurred_image

def save_image(image, file_name):
    try:
        cv2.imwrite(file_name, image)
        print("Image saved successfully")
        return True
    except cv2.error as e:
        print(f"Error: {e}")
        return False

if __name__ == "__main__":
    file_lab = "fileLab.png"
    file_hsv = "fileHSV.png"
    file_rgb = "fileRGB.png"
    file_gray = "fileGRAY.png"
    file_blur = "fileblur.png"
    file_median = "filemedian.png"
    file_sharped = "filesharped.png"

    image = cv2.imread("image.jpg")
    if image is None:
        print("Image is empty")
        exit(1)

    image_lab = cv2.cvtColor(image, cv2.COLOR_BGR2LAB)
    image_hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    image_gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    cv2.imshow("HSV space", image_hsv)
    cv2.imshow("LAB space", image_lab)
    cv2.imshow("RGB space", image_rgb)
    cv2.imshow("GRAY space", image_gray)

    blur_image = blured_image(image)
    cv2.imshow("Gaussian blur", blur_image)

    sharpened_image = sharped_filter(image)
    cv2.imshow("Sharpened filter", sharpened_image)

    median_image = median_blur_filter(image)
    cv2.imshow("Median filter", median_image)

    save_image(image_hsv, file_hsv)
    save_image(image_lab, file_lab)
    save_image(image_rgb, file_rgb)
    save_image(image_gray, file_gray)
    save_image(blur_image, file_blur)
    save_image(sharpened_image, file_sharped)
    save_image(median_image, file_median)

    cv2.waitKey(0)
    cv2.destroyAllWindows()

