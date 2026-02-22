#include <stdio.h>

/**
 * 函数名: add
 * 功能: 计算两个整数的和
 * 参数: 
 *   a - 第一个整数
 *   b - 第二个整数
 * 返回值: 两个整数的和
 */
int add(int a, int b) { 
    return a + b; 
}

int main() {
    // 调用add函数计算2和3的和，并将结果存储在result变量中
    int result = add(2, 3);
    
    // 打印计算结果
    printf("Result: %d\n", result);
    
    return 0;
}