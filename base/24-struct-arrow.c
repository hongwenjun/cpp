#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} Point;

/*
 * 函数: main
 * 功能: 主函数，演示动态内存分配和结构体成员访问的基本用法。
 * 参数: 无
 * 返回值: int - 程序执行状态，0表示正常退出。
 */
int main() {
  // 动态分配一个Point结构体的内存空间，并将指针赋值给p
  Point *p = (Point *)malloc(sizeof(Point));
  
  // 初始化结构体成员x和y的值
  p->x = 2;
  p->y = 3;

  // 打印结构体成员x和y的值
  printf("x: %d\n", p->x);
  printf("y: %d\n", p->y);

  // 释放动态分配的内存
  free(p);

  // 返回程序执行状态
  return 0;
}