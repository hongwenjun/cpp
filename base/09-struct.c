#include <stdio.h>

typedef struct {
  char name[20];
  int age;
} Person;

/*
 * 函数: main
 * 描述: 程序的入口点，用于创建一个Person结构体实例，
 *       初始化其成员变量，并打印相关信息。
 * 参数: 无
 * 返回值: int - 程序执行状态，0表示正常退出。
 */
int main() {
  Person person;  // 声明一个Person类型的变量

  // 初始化person的name字段为"John Doe"
  strcpy(person.name, "John Doe");

  // 初始化person的age字段为25
  person.age = 25;

  // 打印person的name字段
  printf("Name: %s\n", person.name);

  // 打印person的age字段
  printf("Age: %d\n", person.age);

  return 0;  // 返回0表示程序正常结束
}