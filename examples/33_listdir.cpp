#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <iostream>

using namespace boost::filesystem;
using namespace std;

int main()
{
	path p("/sdcard");

	if (!exists(p))
	{
		cout << p << " not found" << endl;
		return 1;
	}

	if (!is_directory(p))
	{
		cout << p << " is not a directory" << endl;
		return 1;
	}

	for (auto &d : directory_iterator(p))
	{
		cout << d << endl;
	}
	return 0;
}
