#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue <int> myq;
	myq.push(100); // 100
	myq.push(200); // 100 200
	myq.push(34); // 100 200 34
	myq.push(999); // 100 200 34 999
	// queue and priority_queue takes dublicate elemnts
	myq.push(999); // 100 200 34 999 999

	cout << "queue.size() = " << myq.size() << endl;
	cout << "queue.empty() = " << myq.empty() << endl;
	cout << "At the front: " << myq.front() << endl;
	cout << "At the back: " << myq.back() << endl;

	while (!myq.empty()) {
		cout << myq.front() << " ";
		myq.pop();
	}
	cout << endl;

	return 0;
}