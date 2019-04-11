#### N-Queens Probelm

- Check $x_1, y_1$ and $x2, y2$ on the same diagonal. if $(x_1 - x_2) = (y_1 - y_2)$ they're on the same diagonal.

#### UVA 11195 - Another n-Queen Problem

The Naive solution I've seen earlier works only for $n <= 8$ only with time complexity upto $O(n!)$.<br>
Now, $\text{Left Diagonal = Right Diagonal = } 2 \times n-1$, for $n = 14$ we have $27$ diagonals.

```cpp
int ans = 0, n;
char board[20][20];
bitset <30> rw, leftDiagonal, rightDiagonal;
void backTrack(int c) {
    if (c == n) { ++ans; return; }
    for (int r = 0; r < n; ++r) {
        if (board[r][c] != '*' && !rw[r] && !leftDiagonal[r-c+n-1] && !rightDiagonal[r+c]) {
            rw[r] = leftDiagonal[r-c+n-1] = rightDiagonal[r+c] = true;
            backTrack(c+1);
            rw[r] = leftDiagonal[r-c+n-1] = rightDiagonal[r+c] = false;
        }
    }
}
int main() {
    int cs = 1;
    while(1) {
        cin >> n;
        if (n == 0) break;
        rw.reset(); leftDiagonal.reset(); rightDiagonal.reset();
        ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        backTrack(0);
        cout << "Case " << cs++ << ": " << ans << endl;
    }
}
```
