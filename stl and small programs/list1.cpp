/*
*	sequence container
*	fast insertion/deletion at the beginning
*	slow operation in the middle	
*/

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void printList(const list <int> &);

int main()
{
	list <int> mylist1(5);
	printList(mylist1);

	list <int> mylist2(5, -1);
	printList(mylist2);

	mylist2.resize(8, 0);
	printList(mylist2);

	mylist1.clear();
	mylist1.push_back(10);
	mylist1.push_back(20); // 10 20
	mylist1.push_back(30); // 10 20 30
	mylist1.push_front(40); // 40 10 20 30
	mylist1.push_front(50); // 50 40 10 20 30
	printList(mylist1);

	mylist1.pop_front(); // 40 10 20 30
	printList(mylist1);

	mylist1.pop_back(); // 40 10 20
	printList(mylist1);

	cout << "mylist1.size() = " << mylist1.size() << endl;
	cout << "mylist2.front() = " << mylist1.front() << endl;
	cout << "mylist2.back() = " << mylist1.back() << endl;


	return 0;
}

void printList(const list <int> &mylist)
{
	list <int>::const_iterator it;

	for(it = mylist.begin(); it != mylist.end(); it++) {
		cout << *it << " ";
	}

	cout << endl;
}











