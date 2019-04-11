```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    string x = "(alpha+omega)^21";
    // a = alpha, b = omega, k = 21 --> to int
    // string.substr(start position, length);
    // string.substr(index) -> trims the string from that position till the end.
    
    string a = x.substr(1, x.find("+") - 1);
    cout << a << endl;

    string b = x.substr(x.find("+") + 1, x.find(")") - x.find("+") - 1);
    cout << b << endl;

    string temp = x.substr(x.find("^") + 1);
    // temp = "21"
    // now convert temp to INT
    int k;
    stringstream ss(x.substr(x.find("^") + 1));
    ss >> k;
    cout << k << endl;
}
```