### Bipartite graph check

```cpp
int main(){
  queue<int> q;
  q.push(source);
  vector <int> color(nodes, INF);
  color[source] = 0;
  bool isBipartite = true;
  while (!q.empty() && isBipartite) {
    int u = q.front(); q.pop();
    for (int j = 0; j < (int) adjList[u].size(); ++j) {
      int v = adjList[u][j];
      if (color[v] == INF) {
        color[v] = 1 - color[u]; // 1 or 0
        q.push(v);
      } else if (color[v] == color[u]) {
        // u and v have same colors!
        isBipartite = false;
        break;
      }
    }
  }
}
```
