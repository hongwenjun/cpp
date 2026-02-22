#include <stdio.h>

/*
 * 函数名: main
 * 功能描述: 演示指针的基本用法，包括变量的值、地址以及指针的声明、赋值和解引用操作。
 * 参数: 无
 * 返回值: int - 程序执行成功时返回0
 */
int main() {
  // 声明一个整型变量并初始化为10
  int num = 10;
  
  // 声明一个指向整型的指针，并将num的地址赋给该指针
  int *ptr = &num;

  // 打印变量num的值
  printf("Value: %d\n", num);
  
  // 打印变量num的内存地址
  printf("Address: %p\n", &num);
  
  // 打印指针ptr中存储的地址（即num的地址）
  printf("Pointer value: %p\n", ptr);
  
  // 解引用指针ptr，打印其指向的值（即num的值）
  printf("Dereference pointer: %d\n", *ptr);

  // 程序正常结束，返回0
  return 0;
}