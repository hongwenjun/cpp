#include <stdio.h>

/*
 * 函数名: main
 * 功能描述: 程序入口函数，演示基本的变量声明、类型转换和输出操作。
 * 参数: 无
 * 返回值: int - 程序执行状态，0表示正常退出。
 */
int main() {
    // 声明并初始化整型变量a和双精度浮点型变量b
    int a = 10;
    double b = 3.14;
    
    // 将整型变量a强制转换为双精度浮点型，并与变量b相加，结果存储在result中
    double result = (double)a + b;
    
    // 输出结果，保留两位小数
    printf("Result: %.2f\n", result);
    
    // 返回0表示程序正常结束
    return 0;
}