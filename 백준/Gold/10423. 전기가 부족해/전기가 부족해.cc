#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w; 
    }
};

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (x == parent[x]) return x;
        else return parent[x] = find(parent[x]);
    }
    void unionSets(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                parent[a] = b;
                size[b] += size[a];
            }
            else if (rank[a] > rank[b]) {
                parent[b] = a;
                size[a] += size[b];
            }
            else {
                parent[b] = a;
                rank[a]++;
                size[a] += size[b];
            }
        }
    }
    int getSize(int x) {
        return size[find(x)];
    }
private:
    vector<int> parent, rank, size;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k; 
    cin >> n >> m >> k;

    vector<int> presets;
    for (int i = 0; i < k; i++)
    {
        int p; cin >> p;
        presets.push_back(p);
    }
    int preset_size = presets.size();

    UnionFind uf(n + 1);
    for (int i = 1; i < preset_size; i++)  uf.unionSets(presets[0], presets[i]);

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end());
    long long totalWeight = 0; 
    for (const auto& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unionSets(edge.u, edge.v);
            totalWeight += edge.w;
        }
    }

    cout << totalWeight << "\n";
    return 0;
}