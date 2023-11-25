#include <stdio.h>

int main() {
  int num = 10;
  int *ptr = &num;

  printf("Value: %d\n", num);
  printf("Address: %p\n", &num);
  printf("Pointer value: %p\n", ptr);
  printf("Dereference pointer: %d\n", *ptr);

  return 0;
}