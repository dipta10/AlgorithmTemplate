---
header-includes:
- \usepackage{fancyhdr}
- \usepackage{graphicx}
- \usepackage[margin=1in,headheight=70pt,headsep=0.3in,includehead]{geometry}
- \pagestyle{fancy}
- \fancyhead[C]{\includegraphics[width=3cm]{header.png} \\ bar header }
- \fancyfoot[L]{\includegraphics[width=5cm]{footer.png}}
- \fancyfoot[C]{foo footer}
- \fancyfoot[R]{\thepage}
output: pdf_document
---
# Longest Increasing Subsequence
> Complexity Of the following code is $O(n^2)$.<br>
> Although there is a $nlog(n)$ solution which is discussed in the later part where we use binary search to get the upper bound.

##### $O(n^2)$ solution
```cpp
/*
 * Editorial: https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
*/
void print(int *ar, int n) {
    for (int i = 0; i < n; ++i) cout << ar[i] << " "; 
    cout << endl;
}
int lisIterative1 (int ar[], int n) {
    // time complexity O(2^n) though I'm not sure
    // source: https://www.youtube.com/watch?v=4fQJGoeW5VE
    int lis[n];
    lis[0] = 1;
    // for (int i = 0; i < n; ++i) lis[i] = 1;
    // it doesn't work here because of '1' --> memset(lis, 1, sizeof(lis));
    
    int mx = 1;
    for (int i = 1; i < n; ++i) {
        lis[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (ar[i] > ar[j] && lis[i] < lis[j]+1) {
                lis[i] = lis[j] + 1;
            }
        }
        mx = max(lis[i], mx);
    }
    cout << "Iterative lis: ";
    print(lis, n);

    return mx;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int ar[] = {3, 2, 4, 5, 4};
    // int ar[] = { 10, 22, 9, 33, 21, 50, 41, 60 };  
    int ar[] = { 10, 22, 9, 33, 21, 50, 41, 60 };  
    int n = sizeof(ar)/sizeof(int);
    cout << lisIterative1(ar, n) << endl;
}
```
##### $O(nlog(n)) \text { solution:}$
```cpp
// Binary search (note boundaries in the caller) 
int CeilIndex(std::vector<int>& v, int l, int r, int key) 
{ 
    while (r - l > 1) { 
        int m = l + (r - l) / 2;  // for overflow
        if (v[m] >= key) r = m; 
        else l = m; 
    } 
    return r; 
} 
int LongestIncreasingSubsequenceLength(std::vector<int>& v) 
{ 
    if (v.size() == 0) return 0; 
  
    std::vector<int> tail(v.size(), 0); 
    int length = 1; // always points empty slot in tail 
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++) { 
        // new smallest value 
        if (v[i] < tail[0]) 
            tail[0] = v[i]; 
        // v[i] extends largest subsequence 
        else if (v[i] > tail[length - 1]) 
            tail[length++] = v[i]; 
        // v[i] will become end candidate of an existing 
        // subsequence or Throw away larger elements in all 
        // LIS, to make room for upcoming grater elements 
        // than v[i] (and also, v[i] would have already 
        // appeared in one of LIS, identify the location 
        // and replace it) 
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
    } 
    return length; 
} 
int main() 
{ 
    std::vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 }; 
    std::cout << "Length of Longest Increasing Subsequence is "
              << LongestIncreasingSubsequenceLength(v) << '\n'; 
    return 0; 
} 
```
