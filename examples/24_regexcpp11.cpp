#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	string s = "Hello, world!";
	regex expr("(\\w+),\\s(\\w+)!");
	string fmt("$1, C++11!");
	cout << regex_replace(s, expr, fmt) << endl;
	return 0;
}
