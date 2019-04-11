// introduction to templates
/*
	Drawback: Code Bloat!
*/

#include <iostream>
#include <string>

using namespace std;

template <typename T>

T square (T n) {
	return (n*n);
}


int main()
{
	cout << square<int>(10) << endl;
	cout << square<double>(10.5) << endl;

	return 0;
}