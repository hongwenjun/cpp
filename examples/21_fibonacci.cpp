#include <iostream>
#include <vector>

using namespace std;

#define COUNT 15

int main()
{
	vector<int> F;
	F.push_back(1); // F(1) = 1
	F.push_back(1); // F(2) = 1
	for (int i = 2; i < COUNT; i++)
	{
		F.push_back(*(F.end() - 1) + *(F.end() - 2)); // F(x) = F(x-1) +
													  // F(x-2)
	}

	cout << "Fibonacci numbers are:" << endl;
	for (int i = 0; i < F.size(); i++)
		cout << F[i] << ' ';

	return 0;
}
