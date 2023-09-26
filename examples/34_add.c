#include <gmp.h>
#include <stdio.h>

int main()
{
	mpz_t a;
	mpz_t b;
	mpz_t c;
	mpz_init_set_str(a, "123456789012345678901234567890", 10);
	mpz_init_set_str(b, "555555555555555555555555555555", 10);
	mpz_init(c);
	mpz_add(c, a, b);
	printf("%s + %s = %s\n", mpz_get_str(NULL, 10, a), mpz_get_str(NULL, 10, b), mpz_get_str(NULL, 10, c));
	return 0;
}
