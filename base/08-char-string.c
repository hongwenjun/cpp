#include <stdio.h>

/*
 * 函数: main
 * 功能: 程序入口点，演示字符串的定义、输出以及用户输入的读取和显示。
 * 参数: 无
 * 返回值: int - 程序执行状态，0表示正常退出。
 */
int main() {
  // 定义一个字符数组并初始化为"John Doe"，用于存储姓名
  char name[20] = "John Doe";
  // 输出姓名到控制台
  printf("Name: %s\n", name);

  // 定义一个字符数组用于存储用户输入的消息
  char message[50];
  // 提示用户输入消息
  printf("Enter a message: ");
  // 从标准输入读取一行文本到message数组中
  fgets(message, sizeof(message), stdin);
  // 输出用户输入的消息到控制台
  printf("You entered: %s\n", message);

  // 返回0表示程序正常结束
  return 0;
}