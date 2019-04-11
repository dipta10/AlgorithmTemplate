/*
properties:
*	sequence container;
*	fast remove/insert at the end: O(1)
*	slow remove/insert at the beginning/middle: 0(n)
	takes linear time actually;
*	slow search: O(n)	
*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(const vector <int> &);

int main()
{
	vector <int> myVector(5, 0); // 0 0 0 0 0
	myVector.push_back(999); 	 // 0 0 0 0 0 999
	myVector.pop_back();		 // 0 0 0 0 0
	
	myVector.insert(myVector.begin() + 2, 34); // 0 0 34 0 0 0
	myVector.clear(); // vector is empty

	for(int i = 0; i < 6; i++) {
		myVector.push_back(i);
	} 
	// 0 1 2 3 4 5 
/*
	if I do this ->
	myVector.erase(myVector.begin() + 2);	
	then the vector would be like 0 1 3 4 5
*/

	myVector.erase(myVector.begin() + 1, myVector.begin() + 4);
/*
	note: iterator erase (iterator first, iterator last);
	Iterators specifying a range within the vector] to be removed: [first,last). 
	i.e., the range includes all the elements between first and last, including 
	the element pointed by first but not the one pointed by last. 
*/

	printVector(myVector);
/*
	myVector.begin() and myVector.end() return the iterator to the first
	and the last position, well kind of o.O
	************MOST IMPORTANT****************
	myVector.end() returns the iterator to the position one after the last
	one.
	MATHEMATICALLY::::::::::: [BEGIN, END)
	or half-open
*/
	myVector.clear();
	for(int i = 5; i >= 1; i--) myVector.push_back(i);
	printVector(myVector);
	// 5 4 3 2 1 

	sort(myVector.begin(), myVector.end());
	printVector(myVector);

/*	sort(myVector.end(), myVector.begin());
	half open, [BEGIN, END)
	so never write a statement like this
*/

	return 0;
}


void printVector(const vector <int> &myVector)
{
	for(int i = 0; i < myVector.size(); i++) {
		cout << myVector[i] << " ";
	}
	cout << endl;
}