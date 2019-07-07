### Coin change problems

#### How many ways to make a change with some coins in your hand.

Be careful with the **size of the DP array**.

- [Video The Change Making Problem - Fewest Coins To Make Change Dynamic Programming](https://www.youtube.com/watch?v=jgiZlGzXMBw&list=PLiQ766zSC5jM2OKVr8sooOuGgZkvnOCTI&index=12)

> Time : O (ChangeAmount $\times$ # of coins)
> Space: O (ChangeAmount $\times$ # of coins)

```cpp
const ll SIZE = 1003 + 10;
ll dp[SIZE][SIZE];
ll coin_cost[SIZE];
ll amount, total_coins;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> amount >> total_coins;
    for (int i = 1; i <= total_coins; ++i) {
        cin >> coin_cost[i];
    }

    for (int i = 1; i <= amount; ++i) dp[0][i] = 0;
    // if I've no coins (0 coins), I can't make a chanage anyway

    for (int i = 0; i <= total_coins; ++i) dp[i][0] = 1;
    // no matter how many coins I've got, if I've to make change for
    // an amount of `0`, then there's only one way to make the
    // change that is, don't take any coins from your bag.

    dp[0][0] = 1;
    // this is redundent though, you've 0 coins in your bag and you
    // need to make change for an amout of 0, as the amount is 0, that means
    // there's one way to make this change

    for (int i = 1; i <= amount; ++i) {
        for (int j = 1; j <= total_coins; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-coin_cost[i]];
            // dp[i-1][j] = number of ways to make change `j` without taking
            // the i-th coin
            // dp[i][j-coin_cost[i]] = number of ways to make change `j` taking the
            // i-th coin. as I've taken the i'th coin, I deduct the valuie of the
            // i'th coin from the amount `j`, as I'm considering the i'th coin, makeing
            // the change equal to `j - coin_cost[i]`
        }
    }
    for (int i = 0; i <= amount; ++i) {
        for (int j = 0; j <= total_coins; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
```

#### CoinChange using recursion, find the minimum number of coins to make a change and you can choose a coin more than once.

```cpp
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int numCoins = 3;
const int INF = 1000000009;
const int sum = 10;
int coins[numCoins] = {1, 3, 4};
int value [sum + 1];
int ready [sum + 1];

int sol (int sum) {
    if (sum < 0) return INF;
    if (sum == 0) return 0;
    if (ready[sum]) return value[sum];
    int best = INF;
    for (int i = 0; i < numCoins; ++i) {
        best = min (best, sol (sum - coins[i]) + 1);
        // best = max (best, sol (sum - coins[i]) + 1);
        // I'm hoping this might give the maximum number of coins needed, not tested though.
    }
    ready[sum] = 1;
    value[sum] = best;
    return value[sum];
}

int main()
{
    cout << sol(10) << endl;
    /*
     * One thing that I've missed in the tutorial.
     * Suppose the coins I'm given are 2, 4, 5
     * now the sum I want  to form is 1.
     * Now that's not possible. That's why sol(1) will return me INF.
     * Now 'INF' means that there's no solution for forming that sum.
     */

    return 0;
}
```
