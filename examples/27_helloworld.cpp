#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>

using namespace boost::algorithm;
using namespace std;

int main()
{
	string hwmod = "  Hell0, w0rld!  ";
	string tmp = replace_all_copy(hwmod, "0", "o");
	tmp = trim_copy(tmp);
	cout << tmp << endl;
	return 0;
}
