#include <stdio.h>
#include <mpc.h>
#include <mpfr.h>

#define PREC 256

int main()
{
	mpc_t rx;
	mpc_t ipi4;
	mpfr_t pi;

	mpfr_set_default_prec(PREC);
	mpc_init2(rx, PREC);
	mpc_init2(ipi4, PREC);
	mpfr_init(pi);
	mpfr_const_pi(pi, MPFR_RNDD);
	mpc_set_fr(ipi4, pi, MPC_RNDDD);
	mpc_mul_i(ipi4, ipi4, 1, MPC_RNDDD);
	mpc_div_ui(ipi4, ipi4, 4, MPC_RNDDD);
	mpc_exp(rx, ipi4, MPC_RNDDD);

	printf("Computed value of e^(i*pi/4) is ");
	mpc_out_str(stdout, 10, 0, rx, MPC_RNDDD);
	printf("\n");
	return 0;
}
