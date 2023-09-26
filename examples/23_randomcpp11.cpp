#include <iostream>
#include <random>

using namespace std;

int main()
{
	random_device rd;
	mt19937 rng(rd());
	uniform_real_distribution<double> dist(0.0, 2.0);
	cout << "Generating 5 random numbers in [0.0; 2.0) range" << endl;
	for (int i = 0; i < 5; i++)
		cout << dist(rng) << " ";
	cout << endl;
	return 0;
}
