#include <stdio.h>

/*
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

/*
 * 函数名: subtract
 * 功能: 计算两个整数的差
 * 参数: 
 *   a - 被减数
 *   b - 减数
 * 返回值: 两个整数的差
 */
int subtract(int a, int b) { 
  return a - b; 
}

/*
 * 函数名: main
 * 功能: 主函数，演示函数指针的使用
 * 参数: 无
 * 返回值: 程序执行状态码
 */
int main() {
  // 声明一个指向函数的指针，该函数接受两个int参数并返回int
  int (*ptr)(int, int);

  // 将函数指针指向add函数
  ptr = add;
  // 调用add函数并通过函数指针打印结果
  printf("Addition: %d\n", ptr(2, 3));

  // 将函数指针指向subtract函数
  ptr = subtract;
  // 调用subtract函数并通过函数指针打印结果
  printf("Subtraction: %d\n", ptr(5, 3));

  // 返回程序执行成功状态
  return 0;
}