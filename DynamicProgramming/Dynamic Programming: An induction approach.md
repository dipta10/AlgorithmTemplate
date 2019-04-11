# Dynamic Programming: An induction approach with Grid Problem
```cpp
/*
 * Created by Dipta Das on 2019-01-22 22:15:55
 * Title: Dynamic Programming: An induction approach (Grid Problem)
 * Problem Link: 
 * Editorial: https://medium.com/@tiagot/dynamic-programming-an-induction-approach-b5c5e73c4a19?fbclid=IwAR2R-cX91F1wM9Ygw4JeKaiDKXYqNsQX5rn9qNl-m_rCG_5iyFuVpZXzIZ0
 * Source Code: 
 * Comments: 
*/

#include <bits/stdc++.h>
#include <stdio.h>
#define fin freopen("input", "r", stdin)
#define endl "\n"
#define whatis(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;
using llu = unsigned long long;

void gen() {
    srand(time(NULL));
    int n = 3, m = 4;
    cout << n << " " << m << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << (rand() % 9) + 1;
            if (j != m-1) cout << " ";
        }
        cout << endl;
    }
}
void print(vector<vector<int>> v) {
    for (auto i : v) {
        for (auto b: i) {
            printf("%3d", b);
        }
        cout << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int row, col;
    cin >> row >> col;

    vector< vector<int> > grid(row+1, vector<int>(col+1, 0));
    vector< vector<int> > sp(row+1, vector<int>(col+1, 0));
     // https://stackoverflow.com/questions/17663186/initializing-a-two-dimensional-stdvector

    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            cin >> grid[i][j];
            sp[i][j] = grid[i][j];
        }
    }

    // don't mess up the next tow 
    for (int i = 2; i <= col; ++i) {
        sp[1][i] = sp[1][i-1] + sp[1][i];
    }
    for (int i = 2; i <= row; ++i) {
        sp[i][1] = sp[i-1][1] + sp[i][1];
    }

    for (int i = 2; i <= row; ++i) {
        for (int j = 2; j <= col; ++j) {
            sp[i][j] = min (sp[i-1][j], sp[i][j-1]) + grid[i][j];
        }
    }
    print(sp);

    cout << "answer: " << sp[row][col] << endl;

    return 0;
}
```