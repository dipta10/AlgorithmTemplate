#### Articulation Point

```cpp
vector < int > adj[maxn];
bool visited[maxn],articulationPoint[maxn];
int low_time[maxn],dfs_time[maxn];
int timer = 0;
void dfs(int u, int p=-1){
    visited[u] = true;
    low_time[u] = dfs_time[u] = timer++;
    int child = 0;
    for(int i = 0; i < (int) adj[u].size(); i++){
        int v = adj[u][i];
        if(v == u) continue;
        if(visited[v]){
            low_time[u] = min(low_time[u], dfs_time[v]); }
        else {
            dfs(v,u);
            if(p != -1 && dfs_time[u] <= low_time[v]){
                articulationPoint[u]=1;
            }
            low_time[u]= min(low_time[u], low_time[v]);
            child++;
        }
    }
    if(p == -1 && child > 1){
        articulationPoint[u]=1;
    }
}
```

> The following code is directly taken from CP3-Felix Halim (pg: 132)

#### Articulation Point and Bridge

- If $\text{DFS\_LOW}_{Child} \ge \text{DFS\_TIME-or-NUM}_{Parent}$ then parent is an articulation point.

I think the code below works fine for bridge problems though I haven't tested it yet.

```cpp
int dfs_low[100005];
int dfs_num[100005];
int dfs_parent[100005];
int dfsNumberCounter = 0;
bitset<100005> articulationVertex;
vector<pair<int,int> > bridge;
vector<vector<int>> adj;
int rootChildren = 0;
int dfsRoot = 0;
void articulationPointAndBridge (int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (int i = 0; i < (int) adj[u].size(); ++i) {
        int v = adj[u][i];
        if (dfs_num[v] == -1) { // if not visited
            dfs_parent[v] = u;
            if (u == dfsRoot) ++rootChildren;
            articulationPointAndBridge(v);
            if (dfs_low[v] >= dfs_num[u]) {
                articulationVertex[u] = 1;
            }
            if (dfs_low[v] > dfs_num[u]) {
                bridge.push_back(make_pair(u, v));
            }
            dfs_low[u] = min (dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min (dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    adj.assign(n, vector<int>());
    memset(dfs_num, -1, sizeof(dfs_num));
    rootChildren = 0;
    articulationVertex.reset();

    for (int i = 0, u, v; i < e; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < e; ++i) {
        if (dfs_num[i] == -1) { // not visited
            dfsRoot = i; rootChildren = 0;
            articulationPointAndBridge(i);
            // following is the speacial case for the root node
            articulationVertex[dfsRoot] = (rootChildren > 1);
        }
    }
    for (int i = 0; i < n; ++i) if (articulationVertex[i]) cout << i << endl;
}
```

#### CAUTION:

```cpp
if (!vis[neighbor]) {
        if (dfsTime[node] <= lowTime[neighbor])
            isArticulation = true;
        else
            lowTime[node] = min(lowTime[node], lowTime[neightbor]);
    } else {
        lowTime[node] = min(lowTime[node], __dfsTime[neighbor]__);
    }
}
```
