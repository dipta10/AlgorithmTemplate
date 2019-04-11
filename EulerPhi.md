<center>Euler Totient or Phi Function</center>

#### source: 
* [forthright48](https://forthright48.com/2015/09/euler-totient-or-phi-function.html)
* Coding Blocks India (I'm yet to watch other videos)

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 10000;
bitset<mx> bs;
vector<int> primes;
void sieve(long long upper_bound) {
    bs.set();
    bs[0] = bs[1] = 0;
    primes.push_back(2);
    for(long long i = 3; i <= upper_bound + 1; i += 2) {
        if(bs[i]) {
            for(long long j = i * i; j <= upper_bound + 1; j += 2*i)
                bs[j] = 0;
            primes.push_back((int) i);
        }
    }
}

int eulerPhi ( int n ) {
    int res = n;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < primes.size() && primes[i] <= sqrtn; i++ ) {
        if ( n % primes[i] == 0 ) {
            while ( n % primes[i] == 0 ) {
                n /= primes[i];
            }
            sqrtn = sqrt ( n );
            res /= primes[i];
            res *= primes[i] - 1;
        }
    }
    if ( n != 1 ) {
        res /= n;
        res *= n - 1;
    }
    return res;
}

int main() {
    sieve(1000);
    cout << eulerPhi(10) << endl;

    return 0;
}
```
### Properties, extensions and related stuff
*   **Euler Totient or Phi $(\Phi)$ function**:<br>Given an integer $N$, how many numbers less than or **equal** to $N$ are there such that they are coprime to $N$? 
    > A number $X$ is coprime to $N$ if $\gcd(X, N) = 1$<br>
    > For example, if $N = 10$, then there are $4$ numbers, namely $1,3,7,9$ which are coprime to $10$.
*   For $n>2, \phi(n)$ is always even.
*   For any prime $p, \phi(p)=p-1$
*   Sum of integers that are coprime to $n$ equals to $\frac{\phi(n)\times n}{2}$.
*   Co-primes doesn't always need to be a prime number as you can see from the previous example $9$ is one of the co-primes of $10$.
*   Euler Phi Extension Theorem: Number of elements $e$, such that $\gcd(e,n) = d$ is equal to $\phi(\frac{n}{d})$
*   **Fermat's Little Theorem**:<br>
    If $a$ and $p$ are coprime and $p$ is a prime, then $a^{p-1} \equiv 1 \pmod p$
*   For any prime $p, \phi (p) = p - 1$

| Tables   |      Are      |  Cool |
|----------|:-------------:|------:|
| col 1 is |  left-aligned | $1600 |
| col 2 is |    centered   |   $12 |
| col 3 is | right-aligned |    $1 |

