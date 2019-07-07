### Stair climbing

##### Recursive DP

- [Video: The Recursive Staircase - Top Down & Bottom Up Dynamic Programming ("Climbing Stairs" on LeetCode)](https://www.youtube.com/watch?v=NFJ3m9a1oJQ&list=PLiQ766zSC5jM2OKVr8sooOuGgZkvnOCTI&index=9&t=0s)

- always make sure you check `sum < 0` first
  If you don't check it then **sum might be negative, let's say -10
  now after that it'll check memo[-10] and it'll give some
  garbage value! YOU DON'T WANNA DO THIS!!!!!!!!!!!!**

```cpp
const int reach = 6;
int start = 0;
vector<int> steps = {1, 2};
const ll total_steps = 2;
ll memo[reach + 1];

ll sol (ll sum) {
    if (sum < 0) return 0;
    // always make sure you check `sum < 0` first
    // if you don't check it then sum might be negative, let's say -10
    // now after that it'll check memo[-10] and it'll give some
    // garbage value! YOU DON'T WANNA DO THIS!!!!!!!!!!!!

    if (memo[sum] > 0) {
        return memo[sum];
    }
    if (sum == 0) return 1;

    ll &total = memo[sum];
    for (int i = 0; i < total_steps; ++i) {
        total = total + sol (sum - steps[i]);
    }

    return total;
}

int main() {
    memset(memo, 0, sizeof(memo));

    cout << sol(reach) << endl;
    return 0;
}
```

##### Iterative approach

```java
public int climbStairs(int n) {

    /*
      In programming we all know we index off of 0. This is why
      we create an array of size n + 1. It is so we can just return
      dp[n] at the end instead of fumbling with dp[n - 1].
      If n = 4 we will get an array like this if we just did "new int[n];":
      [0, 0, 0, 0]
       0  1  2  3
      If we instead do "new int[n + 1" we have:
      [0, 0, 0, 0, 0]
       0  1  2  3  4
       And now we can be literal in how we access the nth subproblem
    */
    int[] dp = new int[n + 1];

    /*
      n = 0, the answer is 1. We can only take no steps.
    */
    dp[0] = 1;

    /*
      n = 1, the answer is 1. We can only take 1 step.
    */
    dp[1] = 1;

    /*
      The answer to the ith subproblem is the sum between the answer
      to the subproblems of climbing i - 1 stairs and i - 2 stairs
    */
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    /*
      This is what we want and built to the while way. The answer for
      the total unique ways to climb n steps when we can either take a
      1 step or 2 step
    */
    return dp[n];
  }
```
