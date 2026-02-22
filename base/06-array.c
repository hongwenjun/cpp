#include <stdio.h>

/*
 * 函数名: main
 * 功能描述: 程序入口函数，用于演示数组的基本操作和输出。
 * 参数: 无
 * 返回值: int - 程序执行状态，0表示正常退出。
 */
int main() {
  // 定义一个包含5个整数的数组，并初始化为{1, 2, 3, 4, 5}
  int numbers[5] = {1, 2, 3, 4, 5};

  // 输出数组的第一个元素
  printf("First element: %d\n", numbers[0]);

  // 输出数组的第二个元素
  printf("Second element: %d\n", numbers[1]);

  // 使用循环遍历数组并逐个输出所有元素
  for (int i = 0; i < 5; i++) {
    printf("%d ", numbers[i]);
  }

  // 返回0表示程序正常结束
  return 0;
}