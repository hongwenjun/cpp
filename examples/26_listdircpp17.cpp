#include <iostream>
#include <filesystem>

using namespace std;
using namespace std::filesystem;

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
		cout << d.path() << endl;
	}
	return 0;
}
