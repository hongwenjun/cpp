#include <boost/regex.hpp>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "Hello, world!";
	boost::regex expr("(\\w+),\\s(\\w+)!");
	string fmt("\\1, Boost.Regex!");
	cout << boost::regex_replace(s, expr, fmt) << endl;
	return 0;
}
