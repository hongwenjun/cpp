#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void threadfunc(int x)
{
	usleep(rand() % 100000);
	cout << "Hello, C++11 (id: " << x << ")" << endl;
}

int main()
{
	srand(time(0));

	thread t1(&threadfunc, 1);
	thread t2(&threadfunc, 2);

	t1.join();
	t2.join();
	return 0;
}
