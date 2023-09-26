#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cout << "Enter some string:" << endl;
	getline(cin, str);
	cout << "Entered string is: \"" << str << "\"" << endl;
	cout << "Its length is " << str.size() << endl;
	string str2 = str + str;
	cout << "Doubled input string is \"" << str2 << "\"" << endl;
	return 0;
}
