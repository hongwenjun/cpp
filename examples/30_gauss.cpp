#include <boost/random.hpp>
#include <cmath>
#include <iostream>

#define mean 0.0
#define sigma 1.0
#define EPS 0.01
#define SAMPLES 10000000

using namespace boost::random;
using namespace std;

int main()
{
	mt19937 rng(static_cast<unsigned int>(time(0)));
	normal_distribution<double> dist(mean, sigma);

	cout << "Generating numbers..." << endl;
	int meanpoints = 0;
	int epoints = 0;
	for (int i = 0; i < SAMPLES; i++)
	{
		double rnd = dist(rng);
		if (fabs(rnd - mean) < EPS)
			meanpoints++;
		if ((fabs(rnd - mean - sqrt(2) * sigma) < EPS) ||
			(fabs(rnd - mean + sqrt(2) * sigma) < EPS))
			epoints++;
	}

	cout << "Expected f(mean)/f(mean+sqrt(2)*sigma): " << M_E << endl;
	cout << "Computed: " << meanpoints * 2.0 / epoints << endl;

	return 0;
}
