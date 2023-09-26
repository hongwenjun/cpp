#include <stdio.h>
#include <mpfr.h>

#define ITER 100

int main()
{
	mpfr_t e_tmp;
	mpfr_t fact;
	mpfr_t tmp;

	mpfr_set_default_prec(256);
	mpfr_init_set_ui(e_tmp, 1, MPFR_RNDD);
	mpfr_init_set_ui(fact, 1, MPFR_RNDD);
	mpfr_init(tmp);

	for (int i = 1; i <= ITER; i++)
	{
		mpfr_mul_ui(fact, fact, i, MPFR_RNDD);
		mpfr_set_d(tmp, 1.0, MPFR_RNDD);
		mpfr_div(tmp, tmp, fact, MPFR_RNDD);
		mpfr_add(e_tmp, e_tmp, tmp, MPFR_RNDD);
	}
	printf("Computed value of e is ");
	mpfr_out_str(stdout, 10, 0, e_tmp, MPFR_RNDD);
	printf("\n");
	return 0;
}
