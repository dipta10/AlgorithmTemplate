#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
 * This template returns the greatest of the elements which are smaller the given element
 * in the list.
 * multiset <int> s = {1, 3, 5, 7};
 * first_less_than(s, 5) ==> 3
 * 1 is also less than 5, but 3 is the one that is the greatest.
 */
template<typename T>
multiset<ll>::iterator first_less_than (const T &ms, ll val) {
    auto it = ms.lower_bound(val);
    if (it == ms.end()) --it;
    while (it != ms.begin() && *it >= val) --it;
    return *it >= val ? ms.end() : it;
}

int main()
{
//    freopen("input", "r", stdin);
    vector <int> v = {1, 3, 5, 7};
    cout << (binary_search(v.begin(), v.end(), 3) ? "Found" : "Not Found") << endl;
    cout << (binary_search(v.begin(), v.end(), 10) ? "Found" : "Not found") << endl;

    vector <int> v1 = {7, 5, 3, 2, 1};
    cout << (binary_search(v1.begin(), v1.end(), 5, greater<int>()) ? "Found" : "Not found") << endl;

    /*
     * lower bound will return an iterator that will point to the first element found greater than
     * or equal to the element given. If it doesn't find any such element it will return an iterator
     * that will point to the end of the vector
     */

    /*
     * upper bound is similar to the lower_bound, the only difference is that it returns iterator
     * to the element which is only "Greater" Than the given element.
     */

    /*
     * I'm not too sure wheather or not I'll have  to use it for a sorted collection of things.
     * but it really doesn't make sense to use it in an unsorted list.
     */

    auto it1 = lower_bound(v.begin(), v.end(), 3);
    auto it2 = lower_bound(v.begin(), v.end(), 4);
    auto it3 = lower_bound(v.begin(), v.end(), 8);

    cout << (it1 != v.end() ? to_string(*it1) : "Not found") << endl; // 3
    cout << (it2 != v.end() ? to_string(*it2) : "Not found") << endl; // 5
    cout << (it3 != v.end() ? to_string(*it3) : "Not found") << endl; // not found

    vector <int> v2 = {1, 3, 7, 9, 11};
    auto it4 = upper_bound(v2.begin(), v2.end(), 3);
    auto it5 = upper_bound(v2.begin(), v2.end(), 4);
    auto it6 = upper_bound(v2.begin(), v2.end(), 11);

    cout << (it4 != v2.end() ? to_string(*it4) : "Not found") << endl;
    cout << (it5 != v2.end() ? to_string(*it5) : "Not found") << endl;
    cout << (it6 != v2.end() ? to_string(*it6) : "Not found") << endl;

    multiset<int> s (v.begin(), v.end());
    auto its1 = s.lower_bound(3);
    auto its2 = s.upper_bound(3);
    cout << (its1 != s.end() ? to_string(*its1) : "not found") << endl;
    cout << (its2 != s.end() ? to_string(*its2) : "not found") << endl;



    return 0;
}
