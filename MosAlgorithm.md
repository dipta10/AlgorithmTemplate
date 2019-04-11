#### Mo's Algorithm

#### Find Number of distinct elements $O(n)$

```cpp
const int mx = 10004;
int ar[mx];
int cnt[mx];
int sol (int n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cnt[ar[i]]++;
        if (cnt[ar[i]] == 1) ++ans;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) { cin >> ar[i]; }
    cout << sol(n) << endl;
}
```
