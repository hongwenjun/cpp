#include <stdio.h>

int main()
{
	int factorial = 3628800;
	int n = 1;
	int tmpfact = 1;
	while (tmpfact < factorial)
	{
		tmpfact *= n;
		n++;
	}
	if (tmpfact == factorial)
		printf("%d is a factorial of %d\n", factorial, n - 1);
	else
		printf("%d is not a factorial\n", factorial);
	return 0;
}
