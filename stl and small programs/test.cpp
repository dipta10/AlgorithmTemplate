#include <cstdio>
#include <list>
#include <set>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <string.h>
#include <algorithm>


using namespace std;

void printVector(const vector <pair <int, int> > &);
void printList (const list <pair <int, int> > &);
void printSet1 (const set <int> &);
void printSet2 (const set<pair <int, int> > &);

const ll MIN = numeric_limits<ll>::min();

template <typename T>
multiset<ll>::iterator firstLessThan (const T& ms, ll val) {
	auto it = ms.lower_bound(val);
	if (it == ms.end()) --it;
	while (it != ms.begin() && *it >= val) --it;
	return *it >= val ? ms.end() : it;
}

ll cal (ll a, ll b, ll c) {
	if (a == MIN || c == MIN) return MIN;
	return (a < b && b < c) ? a*b*c : MIN;
}

int main()
{
	
	
	



	return 0;
}















