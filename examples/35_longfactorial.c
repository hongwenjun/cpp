#include <gmp.h>
#include <stdio.h>

int main()
{
	int n = 100;
	mpz_t factorial;
	mpz_init_set_ui(factorial, 1);
	for (int i = 1; i <= n; i++)
		mpz_mul_ui(factorial, factorial, i);
	printf("Factorial of %d is %s\n", n, mpz_get_str(NULL, 10, factorial));
	return 0;
}