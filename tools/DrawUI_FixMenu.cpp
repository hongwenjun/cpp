// This is free and unencumbered software released into the public domain.
// For more information, please refer to  https://github.com/hongwenjun

// 兰雅VBA代码分享  https://lyvba.com/

#include <stdio.h>
#include <string.h>
#include <string>

using std::string;

bool readfile_DrawUI(string &str, const char *filename);
bool savefile_DrawUI(string &str, const char *filename);
int main() {
  const char *filename = "DrawUI.xml";
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("无法打开文件 DrawUI.xml\n");
    return 1;
  }

  string drawui_text;
  bool flag = readfile_DrawUI(drawui_text, filename);
  bool saveflag = false;

  printf("%d\n", drawui_text.size());

  char guid[] = "f3016f3c-2847-4557-b61a-a2d05319cf18";
  char line[2048];

  string str;
  string menu = "type=\"menu\"";
  string toolbar = "type=\"toolbar\"";

  while (fgets(line, sizeof(line), fp) != NULL) {
    line[strlen(line) - 1] = '\0';

    if (strstr(line, guid) != NULL) {
      str = string(line);
      // 使用 C++ 标准库的 replace() 方法替换单词
      size_t pos = str.find(menu);
      if (pos != string::npos) {
        str.replace(pos, menu.length(), toolbar);
        printf("%s", str.c_str());

        pos = drawui_text.find(string(line));
        if (pos != string::npos) {
          saveflag = savefile_DrawUI(drawui_text, "DrawUI.xml_BAK");
          drawui_text.replace(pos, string(line).length(), str);
        }
      }
    }
  }

  fclose(fp);

  if (saveflag)
    savefile_DrawUI(drawui_text, filename);

  return 0;
}

bool readfile_DrawUI(string &str, const char *filename) {
  FILE *fp;
  long size;
  char *buffer;

  // 打开文件
  fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("打开文件失败\n");
    return false;
  }

  // 获取文件大小
  fseek(fp, 0, SEEK_END);
  size = ftell(fp);
  rewind(fp);

  // 分配内存空间
  buffer = (char *)malloc(size + 1);
  if (buffer == NULL) {
    printf("内存分配失败\n");
    fclose(fp);
    return false;
  }
  // 读取文件内容到内存
  if (fread(buffer, 1, size, fp) != size) {
    printf("读取文件失败\n");
    free(buffer);
    fclose(fp);
    return false;
  }

  // 添加字符串结尾标志
  buffer[size] = '\0';
  str = string(buffer);
  // 释放资源
  free(buffer);
  fclose(fp);
  return true;
}

bool savefile_DrawUI(string &str, const char *filename) {
  FILE *fp;
  const char *content = str.c_str();

  // 打开文件,以写入模式
  fp = fopen(filename, "wb");
  if (fp == NULL) {
    printf("打开文件失败\n");
    return false;
  }
  // 写入字符串到文件
  fputs(content, fp);
  // 关闭文件
  fclose(fp);
  return true;
}