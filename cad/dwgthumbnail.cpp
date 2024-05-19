#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool thumbnail(const char *dwgfile, const char *thumb_bmpfile) {
  FILE *fd = fopen(dwgfile, "rb");
  if (fd == NULL) {
    fprintf(stderr, "无法打开文件\n");
    return false;
  }

  fseek(fd, 13, SEEK_SET);
  unsigned int sentinel_pos;
  fread(&sentinel_pos, sizeof(unsigned int), 1, fd);
  printf("Hex: %X\n", sentinel_pos);

  const int SIZE_SN = 39;

  char buf[SIZE_SN] = {0};
  unsigned char SN[] = {0x1F, 0x25, 0x6D, 0x07, 0xD4, 0x36, 0x28, 0x28,
                        0x9D, 0x57, 0xCA, 0x3F, 0x9D, 0x44, 0x10, 0x2B};
  fseek(fd, sentinel_pos, SEEK_SET);
  fread(buf, SIZE_SN, 1, fd);

  bool isdwg = true;
  for (int i = 0; i != 16; i++) {
    isdwg &= ((unsigned char)buf[i] == SN[i]);
  }

  if (isdwg && buf[20] == 2) {
    for (int i = 0; i != sizeof(buf); i++)
      printf("%0.2X ", buf[i] & 0xFF);
  } else {
    return false;
  }

  int data_size;
  memcpy(&data_size, &buf[35], sizeof(int));

  int pos;
  memcpy(&pos, &buf[31], sizeof(int));

  printf("\ndata_size: 0x%0.4X", data_size);
  printf("\npos: 0x%0.4X\n", pos);

  char *bmp_buf = new char[data_size];
  memset(bmp_buf, 0, data_size);

  fseek(fd, pos, SEEK_SET);
  if (fread(bmp_buf, 1, data_size, fd) != data_size) {
    fprintf(stderr, "读取失败\n");
    delete[] bmp_buf;
    fclose(fd);
    return false;
  }

  FILE *bmp_file = fopen(thumb_bmpfile, "wb");
  if (bmp_file == NULL) {
    fprintf(stderr, "无法创建文件\n");
    delete[] bmp_buf;
    fclose(fd);
    return false;
  }
  struct _BITMAP_HEADER {
    char magic[2];
    int file_size;
    int reserved;
    int offset;
  } bmp_h;

  /* Write bmp file header */
  bmp_h.magic[0] = 'B';
  bmp_h.magic[1] = 'M';
  bmp_h.file_size = 14 + data_size; // file header + DIB data
  bmp_h.reserved = 0;
  bmp_h.offset = 14 + 40 + 4 * 256; // file header + DIB header + color table

  // 写 BMP 文件头
  fwrite(&bmp_h.magic[0], sizeof(char), 2, bmp_file);
  fwrite(&bmp_h.file_size, 4, 3, bmp_file);

  // 写bmp 图片数据
  fwrite(bmp_buf, 1, data_size, bmp_file);

  printf ("Success. Written thumbnail image to '%s'\n", thumb_bmpfile);

  delete[] bmp_buf;
  fclose(fd);
  fclose(bmp_file);
  return true;
}

int main(int argc, char *argv[]) {
  const char *filePath = "example.dwg";
  const char *savePath = "thumbnail.bmp";
  if (2 >= argc){
    filePath = argv[1];
    char buf[256] = {0};
    savePath = strcat(strcpy(buf, filePath), ".bmp");
  }
  if (3 == argc)
    savePath  = argv[2];

  thumbnail(filePath, savePath);
  return 0;
}

/*
# 参考代码
# https://github.com/LibreDWG/libredwg/blob/master/programs/dwgbmp.c
# DWG文件的预览图像数据结构
# https://blog.csdn.net/lzljy/article/details/103110823

### dwgbmp.sh  ###
#!/bin/bash

for file in *
do
    if [[ "$file" == *.dwg ]]
    then
        ./dwgthumbnail.exe "$file"
    fi
done

source dwgbmp.sh
*/
