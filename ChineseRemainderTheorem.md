# Chinese Remainder Theorem: Weak Form

#### The weak form of Chinese Remainder Theorem has a **constraint**: members of the array $M$ must be **pairwise coprime**. This means that $\text{GCD}(m_i,m_j) = 1$ where $i \ne j$

```cpp
int extendedEuclid_gcd ( int A, int B, int *X, int *Y ){
    int x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

/** Returns {-1,-1} if invalid input.
    Otherwise, returns {x,L}, where x is the solution unique to mod L
*/
pair<int, int> chinese_remainder_theorem( vector<int> A, vector<int> M ) {
    if(A.size() != M.size()) return {-1,-1}; /** Invalid input*/

    int n = A.size();

    int a1 = A[0];
    int m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/

    /** Merge the solution with remaining equations */
    for ( int i = 1; i < n; i++ ) {
        int a2 = A[i];
        int m2 = M[i];

        /** Merge the two equations*/
        int p, q;
        extendedEuclid_gcd(m1, m2, &p, &q);

        /** We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.*/
        int x = (a1*m2*q + a2*m1*p) % (m1*m2);

        /** Merged equation*/
        a1 = x;
        m1 = m1 * m2;
    }
    if (a1 < 0) a1 += m1; /** Result is not supposed to be negative*/
    return {a1, m1}; /** make user you're using c++11 or above **/
}
```

Given two sequences of numbers $A=[a1,a2,...,an]$ and $M=[m1,m2,...,mn]$, where all elements of $M$ are pairwise coprime, there always exists an unique solution to $x \mod L$, where $L=m1\times m2\times ... \times mn$, such that $x$ satisfies the following linear congruence equations:

$$x≡a_1\pmod {m_1}$$
$$x≡a_2\pmod {m_2}$$
$$...$$
$$x≡a_n\pmod {m_n}$$

incase you've once again forgotten: <br>
$x \% m = a$ can also be written in mathmatical expression as $x \equiv a \pmod m$

In mathematics, saying that $A \equiv B \pmod M$ means that both A and B has same remainder when they are divided by M. For example,
$$5 \equiv 10\pmod 5$$

Suppose we are given the following three congruence equations:
$$x \equiv 3 \pmod 5$$
$$x \equiv 2 \pmod 7$$
$$x \equiv 2 \pmod 8$$
here we have $A = [3,2,2], M=[5,7,8]$ and $L=5\times7\times8=280$<br>
As we can see $5,7,8$ are co-primes i.e. $\text{GCD}(5,7)=1$ and $\text{GCD}(7,8)=1$<br>
Before you continue, please verify yourself that this indeed satisfies the given congruence. Also, $x=58$ is the **smallest** solution and **there exists more than one solution**. $x=58+280 \times k$, where k is any non-negative integer, also satisfies the equations. But as we said before, $x$ is unique when you mod all the solutions with L. This is what it means to have a **solution unique to mod L**.

Complexity: $O(n×log(L))$.

<br>

# Chinese Remainder Theorem:

```cpp
int ext_gcd ( int A, int B, int *X, int *Y ){
    int x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}
int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
/** Works for non-coprime moduli.
 Returns {-1,-1} if solution does not exist or input is invalid.
 Otherwise, returns {x,L}, where x is the solution unique to mod L
*/
pair<int, int> chinese_remainder_theorem( vector<int> A, vector<int> M ) {
    if(A.size() != M.size()) return {-1,-1}; /** Invalid input*/

    int n = A.size();

    int a1 = A[0];
    int m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/

    /** Merge the solution with remaining equations */
    for ( int i = 1; i < n; i++ ) {
        int a2 = A[i];
        int m2 = M[i];

        int g = gcd(m1, m2);
        if ( a1 % g != a2 % g ) return {-1,-1}; /** No solution exists*/

        /** Merge the two equations*/
        int p, q;
        ext_gcd(m1/g, m2/g, &p, &q);

        int mod = m1 / g * m2; /** LCM of m1 and m2*/

        /** We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.*/
        int x = (a1*(m2/g)*q + a2*(m1/g)*p) % mod;

        /** Merged equation*/
        a1 = x;
        if (a1 < 0) a1 += mod; /** Result is not suppose to be negative*/
        m1 = mod;
    }
    return {a1, m1};
}
```
