#include <opencv2/opencv.hpp> //头文件
using namespace cv;           // 包含cv命名空间

#pragma comment(lib, "opencv_world4100.lib")
int main()
{
    Mat img = imread("./img/lena.webp"); // 【1】读入一张图片
    imshow("lena.webp", img);            // 【2】在窗口中显示载入的图片
    waitKey(6000);                       // 【3】等待6000ms后窗口自动关闭
}