#include <iostream>

using namespace std;

template <typename T>
T Max(T a, T b) { return (a > b) ? a : b; }
int main()
{
	int a, b;
	double c, d;
	a = 2;
	b = 7;
	c = 3.5;
	d = 10.25;
	cout << "Maximum of " << a << " and " << b << " is " << Max(a, b) << endl;
	cout << "Maximum of " << c << " and " << d << " is " << Max(c, d) << endl;
	return 0;
}
