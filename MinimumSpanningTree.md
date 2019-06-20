# Minimum Spanning Tree

A minimum spanning tree (MST) or minimum weight spanning tree is a subset of the edges of a **connected**, edge-weighted __**undirected**__ graph that **connects all the vertices together**, without any cycles and with the minimum possible total edge weight.<br>
That is, it is a spanning tree whose sum of edge weights is as small as possible. More generally, any edge-weighted undirected graph (not necessarily connected) has a minimum spanning forest, which is a union of the minimum spanning trees for its connected components.<br>

## Kruskal’s Algorithm:
* Sort the graph edges with respect to their weights.
* Start adding edges to the MST from the edge with the smallest weight until the edge of the largest weight.
* Only add edges which doesn't form a cycle , edges which connect only disconnected components. We will use **Disjoint Sets** here.

```cpp
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
vector<pair <long long, pair<int, int> >> adj;

void initialize() {
    for(int i = 0;i < MAX;++i) id[i] = i;
}
int root(int x) {
    while(id[x] != x) {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y) {
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal() {
    initialize();
    sort(adj.begin(), adj.end());
    int x, y;
    long long cost, minimumCost = 0;
    // edges = (int) adj.size();

    for(int i = 0;i < edges;++i)
    {
        x = adj[i].second.first;
        y = adj[i].second.second;
        cost = adj[i].first;
        if(root(x) != root(y)) {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}
```
> Time Complexity: In Kruskal’s algorithm, most time consuming operation is sorting because the total complexity of the Disjoint-Set operations will be $O(E \times logV)$, which is the overall Time Complexity of the algorithm.

## Prim’s Algorithm

```cpp
using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}
```

> Time Complexity: The time complexity of the Prim’s Algorithm is $O((V+E)logV)$ because each vertex is inserted in the priority queue only once and insertion in priority queue take logarithmic time.

> Use Case: Use Prim's algorithm when you have a graph with lots of edges.<br>For a graph with V vertices E edges, Kruskal's algorithm runs in $O(E log V)$ time and Prim's algorithm can run in $O(E + V log V)$ **amortized** time, if you use a **Fibonacci Heap**. <br>Prim's algorithm is significantly faster in the limit when you've got a really dense graph with many more edges than vertices. Kruskal performs better in typical situations (sparse graphs) because it uses simpler data structures.

Now if I'm given a graph with N nodes and E edges, then is it possible to form a MST? MST is a minimum spanning tree, it's a tree, meaining there must be N-1 edges. If not then we can not build an MST. [LightOj](https://vjudge.net/contest/305942?fbclid=IwAR35XjWI1zZ8T8xccTJx62NzilQ6xZeikSJ3gxDzva1c33J0K8K1PXnv6ME#problem/F)