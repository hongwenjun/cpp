#include <stdio.h>

int main() {
  unsigned int a = 5; // 0000 0101
  unsigned int b = 3; // 0000 0011

  unsigned int result;

  result = a & b; // 0000 0001 (位与)
  printf("Bitwise AND: %u\n", result);

  result = a | b; // 0000 0111 (位或)
  printf("Bitwise OR: %u\n", result);

  result = a ^ b; // 0000 0110 (位异或)
  printf("Bitwise XOR: %u\n", result);

  result = ~a; // 1111 1010 (位取反)
  printf("Bitwise NOT: %u\n", result);

  result = a << 2; // 0001 0100 (左移)
  printf("Left Shift: %u\n", result);

  result = a >> 1; // 0000 0010 (右移)
  printf("Right Shift: %u\n", result);

  return 0;
}