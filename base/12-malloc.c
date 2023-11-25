#include <stdio.h>
#include <stdlib.h>

int main() {
  int *numbers = (int *)malloc(5 * sizeof(int));
  if (numbers != NULL) {
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;
    numbers[4] = 5;

    int i;
    for (i = 0; i < 5; i++) {
      printf("%d ", numbers[i]);
    }

    free(numbers);
  } else {
    printf("Memory allocation failed.\n");
  }

  return 0;
}