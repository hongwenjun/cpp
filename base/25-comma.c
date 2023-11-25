#include <stdio.h>

int main() {
  int a = 2, b = 3, c = 4, result;

  result = (a * b) + (c - a), a++, b++, c++;

  printf("Result: %d\n", result);
  printf("a: %d\n", a);
  printf("b: %d\n", b);
  printf("c: %d\n", c);

  return 0;
}