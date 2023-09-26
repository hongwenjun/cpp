#include <iostream>

using namespace std;

class Square
{
	int size;

  public:
	void set_size(int s);
	int get_size();
	int area() { return size * size; }
};

void Square::set_size(int s) { size = s; }
int Square::get_size() { return size; }
int main()
{
	Square x;
	x.set_size(10);
	cout << "Area of square with side length " << x.get_size() << " is "
		 << x.area() << endl;
	return 0;
}
