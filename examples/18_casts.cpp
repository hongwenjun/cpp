#include <iostream>

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
	Derived *tmp;

	tmp = dynamic_cast<Derived *>(base);
	if (tmp)
		cout << "Base* has been successfully casted to Derived* using dynamic_cast"
			 << endl;
	else
		cout << "dynamic_cast prevented Base* cast to Derived* from happening"
			 << endl;

	tmp = dynamic_cast<Derived *>(derived);
	if (tmp)
		cout << "Derived* has been successfully casted to Derived* using "
				"dynamic_cast"
			 << endl;
	else
		cout << "dynamic_cast prevented Derived* cast to Derived* from happening"
			 << endl;

	tmp = static_cast<Derived *>(base);
	if (tmp)
		cout << "Base* has been successfully casted to Derived* using static_cast"
			 << endl;
	else
		cout << "This actually never happens" << endl;

	tmp = static_cast<Derived *>(derived);
	if (tmp)
		cout
			<< "Derived* has been successfully casted to Derived* using static_cast"
			<< endl;
	else
		cout << "This actually never happens" << endl;

	return 0;
}
