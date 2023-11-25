#include <stdio.h>

int add(int a, int b) { 
  return a + b; }

int subtract(int a, int b) { 
  return a - b; }

int main() {
  int (*ptr)(int, int);

  ptr = add;
  printf("Addition: %d\n", ptr(2, 3));

  ptr = subtract;
  printf("Subtraction: %d\n", ptr(5, 3));

  return 0;
}