#include <stdio.h>

/*
 * 函数名: main
 * 功能描述: 主函数，程序入口点。用于读取用户输入的一个整数，
 *           并判断该数字是正数、负数还是零，然后输出相应的结果。
 * 参数: 无
 * 返回值: int - 程序执行状态，0表示正常退出。
 */
int main() {
  int num;  // 声明一个整型变量用于存储用户输入的数字

  // 提示用户输入一个数字
  printf("Enter a number: ");
  scanf("%d", &num);  // 从标准输入读取一个整数并存储到变量num中

  // 判断输入数字的正负性并输出对应信息
  if (num > 0) {
    printf("Positive number\n");  // 如果num大于0，输出"Positive number"
  } else if (num < 0) {
    printf("Negative number\n");  // 如果num小于0，输出"Negative number"
  } else {
    printf("Zero\n");  // 如果num等于0，输出"Zero"
  }

  return 0;  // 返回0表示程序正常结束
}