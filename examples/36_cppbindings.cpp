#include <gmpxx.h>
#include <iostream>

using namespace std;

int main()
{
	mpz_class a;
	mpz_class b;
	a = "123";
	b = "321";
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	return 0;
}