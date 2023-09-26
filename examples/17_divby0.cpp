#include <exception>
#include <iostream>

using namespace std;

class divby0 : public exception
{
	const char *what() const throw() { return "Cannot divide by 0"; }
};

int divide(int a, int b)
{
	if (b == 0)
		throw divby0();
	return a / b;
}

int main()
{
	try
	{
		int a = 10;
		int b = 5;
		int c = 0;
		int d = 1;
		cout << a << " / " << b << " = " << divide(a, b) << endl;
		cout << a << " / " << c << " = " << divide(a, c) << endl;
		cout << a << " / " << d << " = " << divide(a, d) << endl;
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
