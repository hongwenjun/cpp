#include <stdio.h>

/*
 * 函数名: main
 * 功能描述: 程序的入口函数，用于接收用户输入的一个整数并将其输出。
 * 参数: 无
 * 返回值: int - 程序执行成功时返回0，表示正常退出。
 */
int main() {
    int num;  // 声明一个整型变量用于存储用户输入的数字

    // 提示用户输入一个数字
    printf("Enter a number: ");
    
    // 读取用户输入的整数并存储到变量num中
    scanf("%d", &num);
    
    // 输出用户输入的数字
    printf("You entered: %d\n", num);
    
    return 0;  // 返回0表示程序正常结束
}