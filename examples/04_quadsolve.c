#include <math.h>
#include <stdio.h>

int solvequadeq(double a, double b, double c, double *x1, double *x2)
{
	double D = pow(b, 2) - 4 * a * c;
	if (D < 0)
		return 0;
	if (D == 0)
	{
		*x1 = (-b) / (2 * a);
		return 1;
	}
	else
	{
		*x1 = (-b - sqrt(D)) / (2 * a);
		*x2 = (-b + sqrt(D)) / (2 * a);
		return 2;
	}
}

int main()
{
	double a = 1;
	double b = -4;
	double c = 3;
	printf("Equation: %f*x^2 + %f*x + %f = 0\n", a, b, c);
	double x1, x2;
	int r = solvequadeq(a, b, c, &x1, &x2);
	printf("%d solution(s) found\n", r);
	if (r > 0)
		printf("x1 = %f\n", x1);
	if (r > 1)
		printf("x2 = %f\n", x2);
	return 0;
}
