#include <iostream>
#include <opencv2/opencv.hpp> //头文件
using namespace cv;           // 包含cv命名空间
#pragma comment(lib, "opencv_world4100.lib")
int main()
{
    std::cout << getVersionString() << std::endl;
    return 0;
}