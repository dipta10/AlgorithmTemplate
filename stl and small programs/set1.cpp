#include <iostream>
#include <set>
#include <string>
#include <iterator>

using namespace std;

int main()
{
	set <string> names;
	set <string>::iterator it1;

	names.insert("Abul");
	names.insert("Dabullll");
	names.insert("Babul");
	names.insert("Abul");
/*
	set sorts the elements in lexicographical order
	if the element is identical to one of the existing element of the set,
	then it doesn't take it [unlike queue or priority_queue].

	Abul
	Babul
	Dabullll

	[Abul is identical, therefore it won't be counted]
*/

	for (it1 = names.begin(); it1 != names.end(); it1++) {
		cout << *it1 << endl;	
	}
	cout << endl;

	set <int> values;
	set <int>::iterator it2;
	values.insert(10);
	values.insert(50);
	values.insert(25);
	values.insert(25);
/*
	set sorts the elements in the ascending order, it means in the opposite
	direction of the priority_queue;
	10
	25
	50
*/

	for(it2 = values.begin(); it2 != values.end(); it2++) {
		cout << *it2 << " ";
	}
	cout << endl;

	return 0;
}