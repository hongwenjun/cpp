#include <windows.h>
#include <opencv2/opencv.hpp>

#pragma comment(lib, "opencv_world4100.lib")
using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{

    if (argc != 2) {
        puts("彩色图片去除阴影App  By 蘭雅    捞鱼吧 bbs.lyvba.com\n");
        puts("Usage: removeShadow  image\n");
        int i = getchar();
        return 8;
    }

    Mat src = imread(argv[1]);
    if (src.empty()) {
        puts("Error: Could not open or find the image.\n");
        return 1;
    }

    // 1. 将图像转换为 HSV 色彩空间
    Mat hsv;
    cvtColor(src, hsv, COLOR_BGR2HSV);
    // 分离通道
    vector<Mat> hsvChannels;
    split(hsv, hsvChannels);

    // 2. 对 V 通道进行处理
    Mat vChannel = hsvChannels[2];
    Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
    int iteration = 9;

    // 3. 膨胀和腐蚀操作
    Mat dilateMat;
    morphologyEx(vChannel, dilateMat, MORPH_DILATE, element, Point(-1, -1), iteration);
    Mat erodeMat;
    morphologyEx(dilateMat, erodeMat, MORPH_ERODE, element, Point(-1, -1), iteration);

    // 4. 计算去阴影效果
    Mat calcMat = ~(erodeMat - vChannel);
    normalize(calcMat, calcMat, 0, 255, NORM_MINMAX);

    // 5. 将处理后的 V 通道与原始 H 和 S 通道合并
    hsvChannels[2] = calcMat;
    Mat result;
    merge(hsvChannels, hsv);

    // 6. 将 HSV 转换回 BGR 色彩空间
    cvtColor(hsv, result, COLOR_HSV2BGR);

    // 7. 将结果保存为图像
    imwrite("removeShadow_color.png", result);

    // 去阴影结果保存为图像
    imwrite("removeShadow.png", calcMat);
    imshow("removeShadow.png", calcMat);
    waitKey(50);
    MessageBoxA(NULL, "彩色图片去除阴影操作完成，感谢您的试用!\n原创软件->捞鱼吧 bbs.lyvba.com", "彩色图片去除阴影App  By 蘭雅", MB_ICONINFORMATION);

    return 0;
}