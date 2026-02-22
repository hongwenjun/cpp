#include <stdio.h>

/*
 * 函数: main
 * 功能: 创建一个文件并写入文本内容，然后关闭文件。
 * 参数: 无
 * 返回值: int - 程序执行状态，0表示成功，非0表示失败。
 */
int main() {
  // 打开文件以进行写入操作
  FILE *file = fopen("file.txt", "w");
  
  // 检查文件是否成功打开
  if (file != NULL) {
    // 向文件中写入文本内容
    fprintf(file, "This is some text.");
    
    // 关闭文件
    fclose(file);
    
    // 输出成功信息
    printf("File created and written successfully.\n");
  } else {
    // 输出错误信息
    printf("Error opening file.\n");
  }

  // 返回程序执行状态
  return 0;
}