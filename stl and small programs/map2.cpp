#include <stdio.h>
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main() {
//freopen("input", "r", stdin);
    map <string, int> m;
    map <string, int>::iterator it;

    m["nabil"] = 41;
//    m["arnob"] = 42;
    m.insert(make_pair("arnob", 42));
    m["dipta"] = 43;

    cout << m["dipta"] << endl;

    it = m.begin();

    cout << it -> first << endl;
    cout << it -> second << endl;

    for (it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }




    return 0;
}













