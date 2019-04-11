#include <iostream>

using namespace std;

int main()
{
	//--------------------------------/////\\\\\--------------------------
	// convert string to integer, long, long long etc...
	// there are also other functions like stoll(string to long long), stol etc
	string s1 = "123";
	int i1 = stoi(s1);


	//--------------------------------/////\\\\\--------------------------
	// how to avoid whitespace when taking string as an input
	// let's say I've a string s2, and have to take input for s2 then I'll just write the
	// following statement just prior to taking input for s2
	// in the following example just after taking int 'i2' as input I was not able to take
	// the string s2 as input because of the white space
	// just if I use that cin.ignore() function then it works perfectly.
	int i2;
	cout << "enter an integer: ";
	cin >> i2;
	string s2;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "enter a string: ";
	getline(cin, s2);


	//--------------------------------/////\\\\\--------------------------
	// Using fast I/O
    // If you're using fast I/O then don't use scanf, printf, just use
    // cin and cout.
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

	return 0;
}
