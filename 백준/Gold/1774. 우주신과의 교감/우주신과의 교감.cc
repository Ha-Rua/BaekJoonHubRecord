#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct Edge {
    int u, v;
    double w;
    bool operator<(const Edge& other) const {
        return w < other.w; 
    }
};

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
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
            }
            else if (rank[a] > rank[b]) {
                parent[b] = a;
            }
            else {
                parent[b] = a;
                rank[a]++;
            }
        }
    }
private:
    vector<int> parent, rank;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; 
    cin >> n >> m;
    UnionFind uf(n);
    vector<pair<long long, long long>> nodes(n + 1);
    for (int i = 1; i <= n ; i++) cin >> nodes[i].first >> nodes[i].second;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        uf.unionSets(u, v);
    }
    vector<Edge> edges;
    for (int i = 1; i <= n; i++)
    {
        long long x1 = nodes[i].first;
        long long y1 = nodes[i].second;
        for (int j = i + 1; j <= n; j++)
        {
            long long x2 = nodes[j].first;
            long long y2 = nodes[j].second;
            double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
            edges.push_back({i, j, dist});
        }
    }
    
    sort(edges.begin(), edges.end());
    
    double totalWeight = 0.00; 
    for (const auto& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unionSets(edge.u, edge.v);
            totalWeight += edge.w;
        }
    }

    cout << fixed << setprecision(2) << totalWeight << "\n";
    return 0;
}