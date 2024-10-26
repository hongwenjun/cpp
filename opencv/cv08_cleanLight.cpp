#include <opencv2/opencv.hpp>
#include <windows.h>

#include <stdio.h>
#include <string.h>

#pragma comment(lib, "opencv_world4100.lib")
using namespace cv;
using namespace std;

void removeShadow(const Mat &src, Mat &dst);
void resizeToFitScreen(const Mat &src, Mat &resized, int screenWidth, int screenHeight);
void applyLevels(Mat &img, int black, int white);
void readOrWriteConfig(const char *filename, double *alpha, int *beta, int *black, int *white);
int  main(int argc, char *argv[])
{

    if (argc < 2) {
        puts("文稿一键美白App  By 蘭雅    捞鱼吧 bbs.lyvba.com\n");
        puts("Usage: cleanLight.exe  image  [new_image]\n");
        int i = getchar();
        return 8;
    }

    // 读取输入图像
    Mat src = imread(argv[1]);
    if (src.empty()) {
        puts("Error: Could not open or find the image.\n");
        return -1;
    }

    Mat result;
    removeShadow(src, result);

    // 设置对比度和亮度参数
    double  alpha  = 1.2; // 对比度因子
    int     beta   = 8;   // 亮度偏移
    int     black  = 30;   // 色阶黑阈值
    int     white  = 235;   // 色阶白阈值
    
    const char *inifile = "cleanLight.ini";
    readOrWriteConfig(inifile, &alpha, &beta, &black, &white);

    convertScaleAbs(result, result, alpha, beta);

    // 应用色阶调整
    applyLevels(result, black, white);

    // 7. 将结果保存为图像
    char filename[256] = "removeShadow_color.png";
    if (argc == 3) strcpy(filename, argv[2]);
    imwrite(filename, result);

    // 屏幕分辨率
    int screenWidth  = 1920;
    int screenHeight = 1080;

    // 调整图像大小
    Mat resizedSrc, resizedResult;
    resizeToFitScreen(src, resizedSrc, screenWidth / 2, screenHeight);
    resizeToFitScreen(result, resizedResult, screenWidth / 2, screenHeight);

    // 拼接图像
    Mat combined;
    hconcat(resizedSrc, resizedResult, combined);

    // 显示结果
    imshow("原图和文稿一键美白图像 By 蘭雅", combined);
    waitKey(50);

    MessageBoxA(NULL,"文稿一键美白完成，感谢您的试用!\n原创软件->捞鱼吧 bbs.lyvba.com\n对比度和色阶微调请修改 cleanLight.ini\n",
        "文稿一键美白App  By 蘭雅", MB_ICONINFORMATION);

    return 0;
}

void readOrWriteConfig(const char *filename, double *alpha, int *beta, int *black, int *white)
{
    // 尝试打开文件
    FILE *file = fopen(filename, "r");
    if (file) {
        // 如果文件存在，从中读取变量
        fscanf(file, "%lf %d %d %d", alpha, beta, black, white);
        fclose(file);
        printf("读取成功: alpha = %.2f, beta = %d\n色阶黑白阈值: black = %d, white = %d\n", *alpha, *beta, *black, *white);
    }
    else {
        // 如果文件不存在，创建文件并写入变量
        *alpha = 1.2;
        *beta  = 8;
        *black  = 30; 
        *white  = 235;
        file = fopen(filename, "w");
        if (file) {
            fprintf(file, "%.2f %d %d %d\n", *alpha, *beta, *black, *white);
            fclose(file);
            printf("文件未找到，已创建并写入: alpha = %.2f, beta = %d\n色阶黑白阈值: black = %d, white = %d\n", *alpha, *beta, *black, *white);
        }
        else {
            perror("无法创建文件");
            exit(EXIT_FAILURE);
        }
    }
}

void removeShadow(const Mat &src, Mat &dst)
{
    // 1. 将图像转换为 HSV 色彩空间
    Mat hsv;
    cvtColor(src, hsv, COLOR_BGR2HSV);

    // 分离通道
    vector<Mat> hsvChannels;
    split(hsv, hsvChannels);

    // 2. 对 V 通道进行处理
    Mat vChannel  = hsvChannels[2];
    Mat element   = getStructuringElement(MORPH_RECT, Size(3, 3));
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

void resizeToFitScreen(const Mat &src, Mat &resized, int screenWidth, int screenHeight)
{
    Size srcSize = src.size();
    int  newWidth, newHeight;

    // 检测是宽大还是高大
    if (srcSize.width > srcSize.height) {
        // 按屏幕宽等比缩放
        newWidth  = screenWidth;
        newHeight = srcSize.height * screenWidth / srcSize.width;
    }
    else {
        // 按屏幕高等比缩放
        newHeight = screenHeight;
        newWidth  = srcSize.width * screenHeight / srcSize.height;
    }

    resize(src, resized, Size(newWidth, newHeight));
}

void applyLevels(Mat &img, int black, int white)
{
    // 计算缩放因子
    double scale = 255.0 / (white - black);
    img.convertTo(img, CV_8U, scale, -black * scale);
}