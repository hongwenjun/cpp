#include <iostream>
#include <typeinfo>

using namespace std;

class Base
{
	virtual void dummy()
	{
		// Required to make class polymorphic
	}
	// Some base class
};

class Derived : public Base
{
	// Some derived class
};

int main()
{
	Base *base = new Base;
	Base *derived = new Derived;

	// These outputs are implementation-dependent and may need to be demangled
	cout << "Type of base variable is " << typeid(*base).name() << endl;
	cout << "Type of derived variable is " << typeid(*derived).name() << endl;

	return 0;
}
