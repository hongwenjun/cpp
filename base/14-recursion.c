#include <stdio.h>

/**
 * 计算给定整数的阶乘。
 *
 * @param n 输入的整数，必须为非负数。
 * @return 返回 n 的阶乘结果。如果 n <= 1，返回 1。
 */
int factorial(int n) {
  // 递归终止条件：当 n 小于等于 1 时，返回 1
  if (n <= 1) {
    return 1;
  } else {
    // 递归调用：返回 n 与 (n-1) 的阶乘的乘积
    return n * factorial(n - 1);
  }
}

int main() {
  // 定义一个整数变量并赋值为 5
  int num = 5;
  
  // 调用 factorial 函数计算 num 的阶乘，并将结果存储在 result 中
  int result = factorial(num);
  
  // 打印结果到控制台
  printf("Factorial of %d is %d.\n", num, result);

  // 程序正常退出
  return 0;
}