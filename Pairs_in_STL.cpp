// CPP program to illustrate Pair in STL
#include <iostream>
#include <utility>
using namespace std;

int main()
{
	pair<int, int> PAIR1;

	PAIR1.first = 100;
	PAIR1.second = 200;

	cout << PAIR1.first << " ";
	cout << PAIR1.second << endl;
	return 0;
}
