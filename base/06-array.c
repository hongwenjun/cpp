#include <stdio.h>

int main() {
  int numbers[5] = {1, 2, 3, 4, 5};
  printf("First element: %d\n", numbers[0]);
  printf("Second element: %d\n", numbers[1]);

  for (int i = 0; i < 5; i++) {
    printf("%d ", numbers[i]);
  }
  return 0;
}