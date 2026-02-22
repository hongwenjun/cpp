#include <stdio.h>

/*
 * 函数名: main
 * 功能描述: 程序入口函数，用于演示基本数据类型的声明和输出。
 * 参数: 无
 * 返回值: int - 程序执行状态，0表示正常退出。
 */
int main() {
  // 声明并初始化整型变量age，表示年龄
  int age = 20;
  
  // 声明并初始化浮点型变量weight，表示体重
  float weight = 65.5;
  
  // 声明并初始化字符型变量grade，表示等级
  char grade = 'A';
  
  // 输出年龄信息
  printf("Age: %d\n", age);
  
  // 输出体重信息，保留两位小数
  printf("Weight: %.2f\n", weight);
  
  // 输出等级信息
  printf("Grade: %c\n", grade);
  
  // 返回0表示程序正常结束
  return 0;
}