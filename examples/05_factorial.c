#include <stdio.h>

int main()
{
	int n = 10;
	int factorial = 1;
	for (int i = 1; i <= n; i++)
		factorial *= i;
	printf("Factorial of %d is %d\n", n, factorial);
	return 0;
}
