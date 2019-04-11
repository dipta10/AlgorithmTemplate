# Binomial coefficient, $^nC_r$ or $n \choose k$

$$^nC_k = ^{(n-1)}C_k + ^{(n-1)}C_{(r-1)}$$

```cpp
typedef long long ll;
ll table[50][50];
ll nCr (ll n, ll r) {
    if (r == 1) return n;
    if (n == r) return 1;
    if (table[n][r] != 0) return table[n][r];
    table[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
    return table[n][r];
}
// test input: nCr(20, 10), output: 184756
```
