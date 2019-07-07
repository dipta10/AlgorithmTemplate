### Bellman Ford's Algorithm (Shortest Path):

It depends on the following concept: Shortest path contains at most $N-1$ edges, because the shortest path couldn't have a cycle.
Algorithm Steps:

- The outer loop traverses from $0 \rightarrow n-2$ [`0` base indexing]
- Loop over all edges, check if the **next node distance > current node distance + edge weight**, in this case update the next node distance to "current node distance + edge weight".

This algorithm depends on the **relaxation principle**. In the beginning all vertices have a distance of "Infinity", but only the distance of the source vertex = 0.

The code here is using `0 base indexing`.

```cpp
vector <pair<ll, pair<int, int>>> adj;
// {weight, {from, to}}
ll dis [1000 + 10];
int nodes, edges;
const ll INF = 2e9;
void bellmanFord() {
    for(int i = 0; i < nodes + 2; i++) dis[i] = INF;
    dis[0] = 0;

    for(int i = 0; i < nodes - 1; i++){
        for (int j = 0, from, to, weight; j < edges; ++j) {
            from = adj[j].second.first;
            to = adj[j].second.second;
            weight = adj[j].first;
            if (to == from) continue;
            if (dis[from] != INF && dis[from] + weight < dis[to]) {
                dis[to] = dis[from] + weight;
            }
        }
    }
}

int main() {
    adj.clear();
    cin >> nodes >> edges;
    for(int i = 0, from, to, weight; i < edges; i++){
        scanf("%d%d%d", &from , &to , &weight);
        // if (from == to) continue; // corner case: self loop
        // --from; --to; --> incase the input is given in 1 base index
        adj.push_back(make_pair(weight, make_pair(from, to)));
    }
    bellmanFord();
}
```

> Time Complexity of Bellman Ford algorithm is relatively high $O(V \times E)$, in case $E = V^2$, the time complexity is $O(E^3)$.

Now Bellman-ford algorithm can be used to detect negative cycle. At the heart of the algorithm there is a for loop that seemingly runs for `(node-1) * edges` times. Let's denote the outer loop as $L1$ and the inner loop ase $L2$. After the completion of the L1 and L2, the distances found from the source are not supposed to be changed. Now after the procedure we'll run the $L2$ for one last time, if distance of any node decreases then we can say that there's a negative cycle. Look at the following code, I'll explain DFS just afterwards.

```cpp
bool neg[SIZE];
void dfs (int u) {
    if (neg[u]) return;
    neg[u] = true;
    int len = (int) adj2[u].size();
    for (int i = 0; i < len; ++i) {
        if (!neg[adj2[u][i]]) dfs(adj2[u][i]);
    }
}
void bellman(int source) {
    // normal bellman ford code
    // the following code is for negative cyles detection,
    //running the inner loop (L2) one last time
    // and to detect which nodes are actually unreachable
    for (int i = 0; i < edges; ++i) {
        int u = adj[i].second.first;
        int v = adj[i].second.second;
        int w = adj[i].first;
        if (u == v) continue;
        if (dis[u] != INF && dis[u] + w < dis[v] && !neg[u]) {
            dfs(u);
        }
    }
}
```

Now if we find a negative cycle, the neighbors of the node `u` (from which the negative cycle stems from) will also be unreachable because it's the node where the negative weight starts from. Draw a picture for reassurance.

#### Detecting negative cycle:

```cpp
    bool bellmanFord() {
      // Write the simple bellman method here and just add the last step beneath.
      // Last Step : check for negative-weight cycles.
      for (int i = 0; i < E; i++) {
          int u = graph->edge[i].src;
          int v = graph->edge[i].dest;
          int weight = graph->edge[i].weight;
          if (dist[u] != LLONG_MAX && dist[u] + weight < dist[v])
              return true;
      }

      return false;
    }
```

### Dijkstra's Algorithm

Algorithm steps:

> Dijkstra's Algorithm can't deal with graphs containing negative weights.

- Set all vertices distances = infinity except for the source vertex, set the source distance = 0.
- Push the source vertex in a min-priority queue in the form (distance , vertex), as the comparison in the min-priority queue will be according to vertices distances.
- Pop the vertex with the minimum distance from the priority queue (at first the popped vertex = source).
- If the popped vertex is visited before, just continue without using it.
- Update the distances of the connected vertices to the popped vertex in case of "current vertex distance + edge weight < next vertex distance", then push the vertex with the new distance to the priority queue.
- Apply the same algorithm again until the priority queue is empty.

The following code snippet follows the `0-base indexing` convention.

```cpp
#define SIZE 100000 + 1
vector <pair<int, ll>> adj[SIZE];
ll dis [SIZE];
bool vis[SIZE];
int nodes, edges;
void dijkstra(int source) {
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < nodes; ++i) dis[i] = 1e9;

    dis[source] = 0;
    multiset<pair<ll, int>> s;
    s.insert(make_pair(dis[source], source));
    while (!s.empty()) {
        pair<int, int> p = *s.begin();
        s.erase(s.begin());
        int x = p.second;
        // int wei = p.first; // not used in dijkstra

        if (vis[x]) continue;
        vis[x] = true;

        for (int i = 0; i < (int) adj[x].size(); ++i) {
            int e = adj[x][i].first;
            int w = adj[x][i].second;
            if (dis[x] + w < dis[e]) {
                dis[e] = dis[x] + w;
                s.insert(make_pair(dis[e], e));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> nodes >> edges;
    for (int i = 0; i < nodes + 10; ++i) adj[i].clear();

    for(int i = 0, from, to, weight; i < edges; i++){
        cin >> from >> to >> weight;
        // if (from == to) continue; // corner case: self loop
        // --from; --to; // --> incase the input is given in 1 base index
        adj[from].push_back(make_pair(to, weight));
    }

    dijkstra(0);

    return 0;
}
```

Now how to find the path using Dijkstra? We can apply dijkstra twice like [this](https://www.youtube.com/watch?v=YYTGPiHHB78&feature=youtu.be) or we can simply use a parent array, google it. The problem remains the same, how to print out all the shortest paths if there are multiple ones.
Check out this [Quora Solution](https://www.quora.com/If-multiple-shortest-paths-exists-between-2-nodes-in-an-undirected-graph-is-it-possible-to-print-all-of-them-using-Dijkstras-algorithm)

> Time Complexity of Dijkstra's Algorithm is $O(V^2)$ but with min-priority queue it drops down to $O(V+E\log V)$.

### Floyd–Warshall's Algorithm:

Floyd–Warshall's Algorithm is used to find the shortest paths between between all pairs of vertices in a graph, where each edge in the graph has a weight which is **positive or negative**. The biggest advantage of using this algorithm is that all the shortest distances between any 2 vertices could be calculated in **$O(V^3)$**.

The Algorithm Steps:
For a graph with $N$ vertices:

- Initialize the shortest paths between any vertices 2 with Infinity.
- Find all pair shortest paths that use 0 intermediate vertices, then find the shortest paths that use 1 intermediate vertex and so on.. until using all $N$ vertices as intermediate nodes.
- Minimize the shortest paths between any 2 pairs in the previous operation.
- For any 2 vertices $(i, j)$, one should actually minimize the distances between this pair using the first $k$ nodes, so the shortest path will be: **$min(dist[i][k] + dist[k][j], dist[i][j])$**.
- Now, $dis[i][j]$ represents the shortest path that only uses the first vertices,$dis[k][j]$ represents the shortest path between the pair $k, j$. As the shortest path will be a concatenation of the shortest path from $i$ to $k$, then from $k$ to $j$.

The following code uses `0 base indexing`.

```cpp
#define SIZE 100000 + 1
ll dis [SIZE][SIZE];
int nodes, edges;
void warshall() {
    for(int k = 0; k < nodes; k++) {
        for(int i = 0; i < nodes; i++) {
            for(int j = 0; j < nodes; j++) {
                dis[i][j] = min( dis[i][j], dis[i][k] + dis[k][j] );
            }
        }
    }
}

int main() {
    cin >> nodes >> edges;
    for (int i = 0; i < nodes; ++i) {
        for (int j = 0; j < nodes; ++j) {
            dis[i][j] = 2e9;
            if (i == j) dis[i][j] = 0;
        }
    }

    for(int i = 0, from, to, weight; i < edges; i++){
        // scanf("%d%d%d", &from , &to , &weight);
        cin >> from >> to >> weight;
        // --from; --to; // --> incase the input is given in 1 base index
        // if (from == to) continue; // corner case: self loop
        // if (dis[from][to] < weight) continue;
        // corner case: in this above case we don't take the weight,
        // but to use this one, don't forget to loop through the dis array
        // and initialize values with INF
        dis[from][to] = weight;
        dis[to][from] = weight;
    }
    warshall();
}
```
