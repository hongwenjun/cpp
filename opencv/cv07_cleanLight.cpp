#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib, "opencv_world4100.lib")


using namespace cv;
using namespace std;

void removeShadow(const Mat& src, Mat& dst) {
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
    merge(hsvChannels, hsv);

    // 6. 将 HSV 转换回 BGR 色彩空间
    cvtColor(hsv, dst, COLOR_HSV2BGR);
}


int main(int argc, char** argv) {
    // 读取输入图像
    Mat src = imread("test.webp");
    if (src.empty()) {
        cerr << "无法加载图像\n";
        return -1;
    }

    Mat result;
    removeShadow(src, result);

    // 调整对比度和亮度
    double alpha = 1.1;  // 对比度因子
    int beta = 5;       // 亮度偏移
    convertScaleAbs(result, result, alpha, beta);


    // 获取原始图像比例
    Size srcSize = src.size();

    // 计算显示尺寸，保持比例
    int displayHeight = 1080;
    int displayWidth = srcSize.width * displayHeight / srcSize.height;

    // 调整图像大小以保持比例
    Mat resizedSrc, resizedResult;
    resize(src, resizedSrc, Size(displayWidth, displayHeight));
    resize(result, resizedResult, Size(displayWidth, displayHeight));

    // 拼接图像
    Mat combined;
    hconcat(resizedSrc, resizedResult, combined);

    // 显示结果
    imshow("原图和去除阴影后的图像对比", combined);
    waitKey(0);
    // 保存结果
    imwrite("output.jpg", result);

    return 0;
}