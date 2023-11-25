#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} Point;

int main() {
  Point *p = (Point *)malloc(sizeof(Point));
  p->x = 2;
  p->y = 3;

  printf("x: %d\n", p->x);
  printf("y: %d\n", p->y);

  free(p);

  return 0;
}