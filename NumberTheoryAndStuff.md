#### Number theory and Stuff. Remake

#### 2d matrix using vector if needed:

```cpp
vector< vector<int> > grid (row, vector<int> (col, 0));
```

Incase you get confused:

```cpp
vector<int> myVector (size_of_the_vector, value_of_each_element_in_vector);
```

#### FastMod: $a^b$

```cpp
ll fastExp (ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b&1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}
```

#### FastModuloExponentiation: $a^b \% m$

```cpp
ll fastExp (ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b&1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}
```

```cpp
int ipow (int b, int e) {
    return (e == 0) ? 1 : b * ipow (b, e-1);
}
int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd (b, a%b);
}
int lcm (int a, int b) {
    return (a*b)/gcd(a,b);
}
```

#### Extended Euclid Method: $Ax + By = gcd(A,B)$

$A$ and $B$ are given in the input. Value of $x$ and $y$ will be assigned once the function is called.

```cpp
int x, y, gcd;
void extendedEuclidMethod (int a, int b) {
    if (b == 0) {
        x = 1; y = 0; gcd = a;
        return;
    }
    extendedEuclidMethod(b, a%b);
    int currentX = y;
    int currentY = x - (a/b) * y;
    x = currentX;
    y = currentY;
}
```

#### Find the smallest prime divisor:

The first divisor that I'll find must be a prime number else the number itself is a prime number, so return it.

```cpp
ll div (ll n) {
    for (ll i = 2; i*i <= n; ++i) {
      if (n % i == 0) return i;
    }
    return n;
}
```

#### Properties of Modular Arithmetic:

1.  In mathematics, saying $A \equiv B \pmod M$ means both $A$ and $B$ have same remainder when they are divided by $M$. For example,<br>
    $13 \% 5 = 3$, which could also be written as, $13 \equiv 3 \pmod 5$.
