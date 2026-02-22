#include <stdio.h>

/**
 * 结构体 Flags 用于表示三种颜色标志位的状态。
 * 每个成员变量占用1位，分别表示红色、绿色和蓝色是否被激活。
 */
struct Flags {
    unsigned int isRed : 1;   // 红色标志位，1表示激活，0表示未激活
    unsigned int isGreen : 1; // 绿色标志位，1表示激活，0表示未激活
    unsigned int isBlue : 1;  // 蓝色标志位，1表示激活，0表示未激活
};

/**
 * 主函数：演示如何使用 Flags 结构体设置和读取颜色标志位。
 * 
 * 功能描述：
 * 1. 初始化一个 Flags 结构体实例。
 * 2. 设置各个颜色标志位的值。
 * 3. 打印每个标志位的当前状态。
 * 
 * 返回值：
 * - 返回 0 表示程序正常结束。
 */
int main() {
    struct Flags f;           // 声明一个 Flags 结构体变量

    f.isRed = 1;              // 设置红色标志位为激活状态
    f.isGreen = 0;            // 设置绿色标志位为未激活状态
    f.isBlue = 1;             // 设置蓝色标志位为激活状态

    // 打印各个颜色标志位的状态
    printf("Red: %u\n", f.isRed);    // 输出红色标志位的值
    printf("Green: %u\n", f.isGreen); // 输出绿色标志位的值
    printf("Blue: %u\n", f.isBlue);   // 输出蓝色标志位的值

    return 0;                 // 程序正常退出
}