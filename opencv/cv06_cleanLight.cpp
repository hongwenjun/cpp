#include <windows.h>
#include <opencv2/opencv.hpp>

#include <stdio.h>
#include <string.h>

void readOrWriteConfig(const char *filename, double *alpha, int *beta);

#pragma comment(lib, "opencv_world4100.lib")
using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{

    if (argc < 2) {
        puts("文稿一键美白App  By 蘭雅    捞鱼吧 bbs.lyvba.com\n");
        puts("Usage: cleanLight.exe  image  [new_image]\n");
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

    // 设置对比度和亮度参数
    double alpha = 1.2;  // 对比度因子
    int beta = 8;        // 亮度偏移
    const char *inifile = "cleanLight.ini";
    readOrWriteConfig(inifile, &alpha, &beta);

    convertScaleAbs(result, result, alpha, beta);


    // 7. 将结果保存为图像
    char filename[256]="removeShadow_color.png";
    if (argc == 3) strcpy(filename, argv[2]);
    imwrite(filename, result);


    // 去阴影结果保存为图像
    imwrite("removeShadow.png", calcMat);
    imshow("removeShadow.png", calcMat);
    waitKey(50);
    MessageBoxA(NULL, "文稿一键美白完成，感谢您的试用!\n原创软件->捞鱼吧 bbs.lyvba.com\n亮度和对比调整请修改cleanLight.ini", "文稿一键美白App  By 蘭雅", MB_ICONINFORMATION);

    return 0;
}


void readOrWriteConfig(const char *filename, double *alpha, int *beta) {
    // 尝试打开文件
    FILE *file = fopen(filename, "r");
    if (file) {
        // 如果文件存在，从中读取变量
        fscanf(file, "%lf %d", alpha, beta);
        fclose(file);
        printf("读取成功: alpha = %.2f, beta = %d\n", *alpha, *beta);
    } else {
        // 如果文件不存在，创建文件并写入变量
        *alpha = 1.2;
        *beta = 8;

        file = fopen(filename, "w");
        if (file) {
            fprintf(file, "%.2f %d\n", *alpha, *beta);
            fclose(file);
            printf("文件未找到，已创建并写入: alpha = %.2f, beta = %d\n", *alpha, *beta);
        } else {
            perror("无法创建文件");
            exit(EXIT_FAILURE);
        }
    }
}

