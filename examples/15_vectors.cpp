#include <iostream>

using namespace std;

class Vector
{
  public:
	int x;
	int y;
	Vector(int x, int y) : x(x), y(y) {}
	Vector operator+(const Vector &right)
	{
		Vector result(x + right.x, y + right.y);
		return result;
	}
};

std::ostream &operator<<(std::ostream &Str, Vector const &v)
{
	Str << "[" << v.x << "," << v.y << "]";
	return Str;
}

int main()
{
	Vector x(2, 3);
	Vector y(4, 5);
	cout << "Sum of vectors " << x << " and " << y << " is " << x + y << endl;
	return 0;
}
