#include <stdio.h>

/**
 * 自行实现strlen函数
 * @param s 字符串指针
 * @return 字符串的长度
 */
size_t strlen_diy(const char *s) {
  const char *a = s;
  while (*s++)
    ;
  return s - a - 1;
}

/**
 * 自行实现memchr函数
 * @param src 源数据指针
 * @param c 要查找的字符
 * @param n 检查的字符数
 * @return 找到字符的指针，或NULL
 */
void *memchr_diy(const void *src, int c, size_t n) {
  const unsigned char *s = src;
  c = (unsigned char)c;

  for (; n && *s != c; s++, n--)
    ;

  return n ? (void *)s : 0;
}

/**
 * 自行实现strnlen函数
 * @param s 字符串指针
 * @param n 最大检查长度
 * @return 字符串的实际长度，或n
 */
size_t strnlen_diy(const char *s, size_t n) {
  const char *p = memchr_diy(s, 0, n);
  return p ? p - s : n;
}

/**
 * 自行实现strcpy函数
 * @param d 目标字符串指针
 * @param s 源字符串指针
 * @return 目标字符串指针
 */
char *strcpy_diy(char *d, const char *s) {
  char *p = d;
  // for (; (*d = *s); s++, d++) ;
  while ((*d++ = *s++))
    ;
  return p;
}

/**
 * 自行实现strcat函数
 * @param d 目标字符串指针
 * @param s 源字符串指针
 * @return 目标字符串指针
 */
char *strcat_diy(char *d, const char *s) {
  strcpy_diy(d + strlen_diy(d), s);
  return d;
}

int main() {
  char str[] = "Hello World -> (strlen_diy memchr_diy strcpy_diy strcat_diy)";
  // 使用memchr_diy查找字符'('的位置
  puts(memchr_diy(str, '(', strlen_diy(str)));

  // 使用strlen_diy计算字符串长度
  int len = strlen_diy(str);
  printf("len: %d\n", len);

  // 使用strnlen_diy计算字符串长度，限制最大检查长度为100
  len = strnlen_diy(str, 100);
  printf("len: %d\n", len); 

  // 使用strcpy_diy复制字符串
  char *s = strcpy_diy(str, "Hello C/C++ LIBC:");
  printf("%s\n", s);

  // 使用strcat_diy追加字符串
  s = strcat_diy(str, "-> strcat_diy");
  printf("%s\n", s);
  return 0;
}

