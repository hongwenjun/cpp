#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

#pragma comment(lib, "opencv_world4100.lib")
using namespace std;
using namespace cv;

int main()
{
    Point2f p(6, 2);
    cout << "【2维点】p = " << p << ";\n" << endl;

    Point3f p3f(8, 2, 0);
    cout << "【3维点】p3f = " << p3f << ";\n" << endl;

    vector<float> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);

    vector<Point2f> points(20);
    for (size_t i = 0; i < points.size(); ++i) points[i] = Point2f((float)(i * 5), (float)(i % 7));

    cout << "【二维点向量】points = " << points << ";";
}