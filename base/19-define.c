#include <stdio.h>

#define PI 3.14159
#define SQUARE(x) ((x) * (x))

/*
 * 函数名: main
 * 功能描述: 计算给定半径的圆的面积，并将结果打印到控制台。
 * 参数: 无
 * 返回值: int - 程序执行状态，0表示正常退出。
 */
int main() {
    // 定义圆的半径为2.5
    float radius = 2.5;
    
    // 使用宏SQUARE计算半径的平方，并结合PI计算圆的面积
    float area = PI * SQUARE(radius);
    
    // 打印计算得到的圆的面积，保留两位小数
    printf("Area: %.2f\n", area);
    
    // 返回0表示程序正常结束
    return 0;
}