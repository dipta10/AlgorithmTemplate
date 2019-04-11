#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <string>

using namespace std;

int main()
{
	// using iterator with maps
	map <string, int> mymap; 
	map <string, int>::iterator it1;

	mymap.insert(make_pair("Dipta", 43));
	mymap.insert(make_pair("Nabil", 41));
	mymap.insert(make_pair("Arnob", 42));

	for(it1 = mymap.begin(); it1 != mymap.end(); it1++) {
		cout << it1->first << " " << it1->second << endl;
	}
	cout << endl << endl;

	// using with vector
	vector <int> myvec;
	vector <int>::iterator it2;
	myvec.push_back(10);
	myvec.push_back(20);
	myvec.push_back(30);
	myvec.push_back(40);
	// 10 20 30 40

	for(it2 = myvec.begin(); it2 != myvec.end(); it2++) {
		cout << *it2 << " ";
	}
	cout<<endl;



	return 0;
}