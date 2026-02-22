#include <stdio.h>

/*
 * 函数名: main
 * 功能描述: 程序入口函数，执行一系列算术运算并输出结果。
 * 参数: 无
 * 返回值: int - 程序退出状态，0表示正常退出。
 */
int main() {
  int a = 2, b = 3, c = 4, result;

  // 执行复合表达式：先计算 (a * b) + (c - a)，然后对 a、b、c 进行自增操作
  result = (a * b) + (c - a), a++, b++, c++;

  // 输出计算结果和变量 a、b、c 的当前值
  printf("Result: %d\n", result);
  printf("a: %d\n", a);
  printf("b: %d\n", b);
  printf("c: %d\n", c);

  return 0;
}