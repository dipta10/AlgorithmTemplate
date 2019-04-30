### Max Range Sum

#### Kadane's Algorithm $O(n)$:

```cpp
int main() {
    int n = 9, ar[] = { 4, -5, 4, -3, 4, 4, -4, 4, -5 };
    int sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += ar[i];
        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }
    cout << "ANS_SUM : " << ans << endl;
}
```

I need to check this one to find out the range:

```cpp
for (int i = 0; i < n; ++i) {
    sum += ar[i];
    if (sum >= ans) {
        ans = sum;
        idx2 = i;
    }
    if (sum < 0) {
        sum = 0;
        if (idx1 <= idx2) prev = idx1;
        idx1 = i + 1;
    }
    // cout << "SUM: " << sum << " IDX1: " << idx1 << " IDX2: " << idx2 << endl;
}
```
