#include <bits/stdc++.h>
using namespace std;

#define MAXN 50

int n, m;
vector<pair<int, pair<int, int>>> edges;
int parent[MAXN], size[MAXN];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    parent[y] = x;
    size[x] += size[y];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    int subgraph_size;
    cin >> subgraph_size;
    vector<int> subgraph_nodes(subgraph_size);
    for (int i = 0; i < subgraph_size; i++) {
        cin >> subgraph_nodes[i];
    }

    int mst_weight = 0;
    for (auto e : edges) {
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if (find(u) != find(v) &&
            (find(subgraph_nodes.begin(), subgraph_nodes.end(), u) != subgraph_nodes.end()) &&
            (find(subgraph_nodes.begin(), subgraph_nodes.end(), v) != subgraph_nodes.end())) {
            unite(u, v);
            mst_weight += w;
        }
    }

    cout << mst_weight << endl;

    return 0;
}
