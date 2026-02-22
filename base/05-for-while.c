#include <stdio.h>

/*
 * 函数: main
 * 功能: 程序入口点，演示了三种循环结构的使用：for循环、while循环和do-while循环。
 * 参数: 无
 * 返回值: int - 程序执行成功时返回0
 */
int main() {
  // 使用for循环打印数字1到8
  for (auto i = 1; i <= 8; i++)
    printf("%d ", i);

  // 使用while循环从8递减打印到1
  int j = 8;
  while (j > 0)
    printf("%d ", j--);

  // 使用do-while循环打印数字1到8
  int k = 1;
  do {
    printf("%d ", k++);
  } while (k <= 8);

  return 0;
}