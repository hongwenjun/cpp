#include <math.h>
#include <stdio.h>

struct Point
{
	int x;
	int y;
};

double dist(struct Point *a, struct Point *b)
{
	return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

int main()
{
	struct Point p1;
	struct Point p2;
	p1.x = 1;
	p1.y = 0;
	p2.x = 0;
	p2.y = 1;
	printf("Distance between points [%d, %d] and [%d, %d] is %f\n", p1.x, p1.y,
		   p2.x, p2.y, dist(&p1, &p2));
	return 0;
}
