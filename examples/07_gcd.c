#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main()
{
	int a = 10;
	int b = 15;
	printf("Greatest common divisor of %d and %d is %d\n", a, b, gcd(a, b));
	return 0;
}
