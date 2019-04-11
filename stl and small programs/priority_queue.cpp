#include <iostream>
#include <queue>
#include <string>
#include <iterator>

using namespace std;

int main()
{
	priority_queue <int> myq;
	vector <int>::iterator it;

	myq.push(50);
	myq.push(20);
	myq.push(100);
	// queue and priority_queue takes dublicate elemnts
	myq.push(100);

	// remember your can't iterate through queues

	while(!myq.empty()) {
		cout << myq.top() << endl;
		// ********* it's top() not front() ********
		myq.pop();
	}

	priority_queue <string> myq2;
	myq2.push("Abullll");
	myq2.push("Dabul");
	myq2.push("Babul");
/*
	remember::::::::
	priority_queue sorts string in the opposite direction of the
	lexicographical order. [The string length has nothing to do with it as well]
	Dabul
	Babul
	Abulllll
*/

	while(!myq2.empty()) {
		cout << myq2.top() << endl;
		myq2.pop();
	}



	return 0;
}