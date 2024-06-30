#include <stdio.h>
size_t strlen_diy(const char *s) {
  const char *a = s;
  for (; *s; s++)
    ;
  return s - a;
}

void *memchr_diy(const void *src, int c, size_t n) {
  const unsigned char *s = src;
  c = (unsigned char)c;

  for (; n && *s != c; s++, n--)
    ;

  return n ? (void *)s : 0;
}

size_t strnlen_diy(const char *s, size_t n) {
  const char *p = memchr_diy(s, 0, n);
  return p ? p - s : n;
}

int main() {
  char str[] =
      "Locate character in block of memory\n"
      "Searches within the first num bytes of the block of memory pointed by "
      "ptr for the first occurrence of value (interpreted as an unsigned "
      "char), and returns a pointer to it.";
  puts(memchr_diy(str, '(', strlen_diy(str)));

  int len = strnlen_diy(str, 512);

  printf("len: %d\n", len);

  return 0;
}