#include <iostream>
#include <utility> // for the std::pair, std::make_pair
#include <vector>

using namespace std;

int main()
{
	//declaration
	pair <int, int> pa1;
	pa1 = make_pair(10, 2);

	pair <string, int> pa2;
	pa2.first = "zero";
	pa2.second = 0;

	pair <double, float> pa3 (10.5, 9.8f);
	pa3.second = 999.99f;

	cout << pa1.first << " " << pa1.second << endl;
	cout << pa2.first << " " << pa2.second << endl;
	cout << pa3.first << " " << pa3.second << endl;

	// pair with vectors
	vector < pair <int, int> > vp;
	vp.push_back(make_pair(10, 11));
	vp.push_back(make_pair(20, 21));


	cout << "The vector with pari is:" <<endl;
	cout << vp[0].first << " " << vp[0].second << endl;
	cout << vp[1].first << " " << vp[1].second << endl;

	return 0;
}