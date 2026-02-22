#include <stdio.h>
#include <stdlib.h>

/*
 * 函数: main
 * 功能: 主函数，演示动态内存分配、数组初始化、遍历输出以及内存释放的过程。
 * 参数: 无
 * 返回值: int - 程序执行状态，正常退出返回0。
 */
int main() {
  // 动态分配一个包含5个整数的数组内存空间
  int *numbers = (int *)malloc(5 * sizeof(int));
  
  // 检查内存分配是否成功
  if (numbers != NULL) {
    // 初始化数组元素
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;
    numbers[4] = 5;

    // 遍历并打印数组中的每个元素
    int i;
    for (i = 0; i < 5; i++) {
      printf("%d ", numbers[i]);
    }

    // 释放动态分配的内存
    free(numbers);
  } else {
    // 内存分配失败时输出错误信息
    printf("Memory allocation failed.\n");
  }

  // 返回程序执行状态
  return 0;
}