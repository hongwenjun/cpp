#include <opencv2/opencv.hpp>

#pragma comment(lib, "opencv_world4100.lib")
using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        puts("Usage: cv04_removeShadow image\n");
        return 8;
    }

    Mat src = imread(argv[1]);
    // 1.将图像转为灰度图
    Mat gray;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    // imshow("gray", gray);

    // 定义腐蚀和膨胀的结构化元素和迭代次数
    Mat element   = getStructuringElement(MORPH_RECT, Size(3, 3));
    int iteration = 9;

    // 2.将灰度图进行膨胀操作
    Mat dilateMat;
    morphologyEx(gray, dilateMat, MORPH_DILATE, element, Point(-1, -1), iteration);
    // imshow("dilate", dilateMat);

    // 3.将膨胀后的图再进行腐蚀
    Mat erodeMat;
    morphologyEx(dilateMat, erodeMat, MORPH_ERODE, element, Point(-1, -1), iteration);
    // imshow("erode", erodeMat);

    // 4.膨胀再腐蚀后的图减去原灰度图再进行取反操作
    Mat calcMat = ~(erodeMat - gray);
    // imshow("calc", calcMat);

    // 5.使用规一化将原来背景白色的改了和原来灰度图差不多的灰色
    Mat removeShadowMat;
    normalize(calcMat, removeShadowMat, 0, 200, NORM_MINMAX);
    // imshow("dst", removeShadowMat);

    // waitKey(0);

    imwrite("removeShadow.png", removeShadowMat);

    return 0;
}