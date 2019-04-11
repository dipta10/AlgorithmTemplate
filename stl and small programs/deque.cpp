/*
properties:
*	fast removal/insertion at the beginning and end: O(1);
*	slow removal/insertion at the middle: O(n) [linear funciton]
*	slow search: O(n)
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <iterator>

using namespace std;

void printDeque(deque<int> &);

int main()
{
	deque <int> dq; 

	dq.push_back(10); // 10
	dq.push_front(20); // 20 10
	dq.push_back(30); // 20 10 30
	dq.push_front(40); // 40 20 10 30
	dq.push_back(99); // 40 20 10 30 99 
/*
	C++98 doesn't let us initialize deque like the following example:
	deque <int> dq = {1, 2, 3};
*/
	cout << "at dq[1]: "<< dq[1] << endl; // can be used like a vector

	printDeque(dq);


	return 0;
}


void printDeque(deque<int> &dq)
{
/*
	to iteraterate through a deque, queue or whatever, never use const
	as the parameter, otherwise you'll get error!
	if You want to use cont then use const_iterator instead of iterator only.
*/
	deque <int>::iterator it;
	for(it = dq.begin(); it != dq.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}













