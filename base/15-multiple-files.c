// 15.多文件编程
// file1.c
#include <stdio.h>

void sayHello() { 
  printf("Hello from file1.c!\n"); 
}

// file2.c
#include <stdio.h>

void sayHello(); // 函数声明

int main() {
  sayHello();
  return 0;
}

// 编译和链接两个文件：
// gcc file1.c file2.c -o program