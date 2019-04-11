/*
properties:
*	insertion at anywhere takes O(long(n)) times, fast
*	finding an element is very very fast: O(log(n))	
*/
#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	set <int> myset;
	myset.insert(3); // 3
	myset.insert(1); // 1 3
	myset.insert(7); // 1 3 7

	set<int>::iterator it;
	it = myset.find(7); // 'it' now points to 7
						// very fast: O(log(n))

/*
	one very important thing:
	the value of elements in set/multi-set can not be modified.
	like, *it = 10; // it's not possible, it's read only;
*/

/*
	the insert() functions returns a pair of values. [shown below]
	the second value returns a boolen to indicate whether the insertion is
	successful or not.
	the first element of the pair is an iterator.
	if the insertion is completed then the iterator points to the inserted
	element. if the insertion is not completed the iterator points to the 
	duplicate value already existing in the set.
*/
	pair <set<int>::iterator, bool> ret;
	ret = myset.insert(3); // no element inserted
	if (ret.second == false) {
		it = ret.first; // therefore, 'it' now points to 3 in myset
	}

	myset.insert(it, 9); // 1 3 7 9
/*
	then why use iterator in insert() function?
	well it's because iterator is given as a hint as to where to position 9
	if I can give a good hint then I can reduce the time from
	O(log(n)) to constant time O(1);
*/

	myset.erase(it); // removes 3 from the set
					 // 1 7 9		
	myset.erase(7);  // removes 7 from the set
					 /// 1 9
// we can erase both using iterator and the value.


	return 0;
}