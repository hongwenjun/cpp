#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string, string> db;
	cout << "Welcome to the simplest key-value database" << endl;
	while (1)
	{
		cout << "What do you want to do?" << endl;
		cout << "Enter P to [P]ut, G to [G]et or L to [L]ist" << endl;
		cout << "Or enter Q to [Q]uit" << endl;
		string action;
		getline(cin, action);
		if (action == "P")
		{
			string key;
			string data;
			cout << "Enter key: ";
			getline(cin, key);
			cout << "Enter data: ";
			getline(cin, data);
			db[key] = data;
		}
		if (action == "G")
		{
			cout << "Enter key: ";
			string key;
			getline(cin, key);
			if (db.find(key) != db.end())
			{
				cout << "Your data: " << db[key] << endl;
			}
			else
				cout << "No such key" << endl;
		}
		if (action == "L")
		{
			cout << "DB contents:" << endl;
			for (auto it = db.begin(); it != db.end(); it++)
			{
				cout << it->first << ": " << it->second << endl;
			}
		}
		if (action == "Q")
		{
			cout << "Bye" << endl;
			break;
		}
		cout << endl;
	}

	return 0;
}
