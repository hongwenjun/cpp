#include <stdio.h>

int main() {
  for (auto i = 1; i <= 8; i++)
    printf("%d ", i);

  int j = 8;
  while (j > 0)
    printf("%d ", j--);

  int k = 1;
  do {
    printf("%d ", k++);
  } while (k <= 8);

  return 0;
}