#include <iostream>
#include <vector>
using namespace std;
class UnionFind {
public:
    UnionFind(int n, const vector<int>& components) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 0);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            size[i] = ((components[i] > 0) ? 1 : -1);
        }
    }
    int find(int x) {
        if (x == parent[x]) return x;
        else return parent[x] = find(parent[x]);
    }
    void unionSets(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) {
            if (rank[a] < rank[b])
            {
                parent[a] = b;
                size[b] += size[a];
            }
            else if (rank[a] > rank[b])
            {
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
    int getSize(int x)
    {
        return size[find(x)];
    }
private:
    vector<int> parent, rank, size;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, q; cin >> n >> m >> q;
    vector<int> components;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        components.push_back(x);
    }
    UnionFind uf(n, components);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        uf.unionSets(a - 1, b - 1);
    }
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        if (uf.getSize(x - 1) > 0)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}