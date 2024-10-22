#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world4100.lib")
using namespace cv;

int main()
{
    Mat  image = imread("./img/lena.webp");
    Rect rect1(256, 256, 128, 128);
    Rect rect2(224, 224, 128, 128);

    Mat roi1;
    image(rect1).copyTo(roi1); // 将image中rect1的部分复制到roi1中
    imshow("1", roi1);
    waitKey(0);

    Mat roi2;
    image(rect2).copyTo(roi2); // 将image中rect2复制到roi2中
    imshow("2", roi2);
    waitKey(0);

    cv::Rect rect3 = rect1 & rect2; // rect1和rect2的交集
    Mat      roi3;
    image(rect3).copyTo(roi3);
    imshow("3", roi3);
    waitKey(0);

    Rect rect4 = rect1 | rect2; // rect1和rect2的并集(两幅图的最小外接矩形)
    Mat  roi4;
    image(rect4).copyTo(roi4);
    imshow("4", roi4);
    waitKey(0);

    Rect rect5(10, 10, 128, 128);
    roi1.copyTo(image(rect5)); // 将rect1复制到image的指定区域rect5中
    imshow("5", image);
    waitKey(0);
}