#include <stdio.h>

/**
 * 函数: greet
 * 功能: 打印问候语，包含姓名和消息。
 * 参数:
 *   - name: 指向字符数组的指针，表示要问候的姓名。如果为NULL，则默认使用"Guest"。
 *   - message: 指向字符数组的指针，表示要显示的消息。
 * 返回值: 无
 */
void greet(char *name, char *message) {
  // 如果name为NULL，则将其设置为默认值"Guest"
  if (name == NULL) {
    name = "Guest";
  }
  // 打印问候语，格式为"Hello, [name]! [message]"
  printf("Hello, %s! %s\n", name, message);
}

/**
 * 函数: main
 * 功能: 程序入口点，调用greet函数进行测试。
 * 参数: 无
 * 返回值: 整型，表示程序退出状态（0表示正常退出）。
 */
int main() {
  // 调用greet函数，传入NULL作为姓名，测试默认值逻辑
  greet(NULL, "Welcome to the program.");
  // 调用greet函数，传入具体姓名和消息
  greet("John", "Nice to meet you.");

  // 返回0表示程序正常结束
  return 0;
}