#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <string>

using namespace std;

int main()
{
	map <string, int> mymap;
	map <string, int>::iterator it;
	mymap["Abul"] = 43;
	mymap["Dabul"] = 10;
	mymap.insert(make_pair("Babul", 20));
/*
	now the map is sorted itself based on the keys
	Abul 	43
	Babul 	20
	Dabul	10
*/

	for(it = mymap.begin(); it != mymap.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}



	return 0;
}