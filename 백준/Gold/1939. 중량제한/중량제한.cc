#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
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
    int n, m; cin >> n >> m;
    UnionFind uf(n);
    vector<int> lines[m + 1];
    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        lines[i] = {c, a, b};
    }
    sort(lines + 1, lines + m + 1, greater<vector<int>>());
    int start, end; cin >> start >> end;
    int res;
    for (int i = 1; i <= m; i++) {
        int c = lines[i][0];
        int a = lines[i][1];
        int b = lines[i][2];
        uf.unionSets(a - 1, b - 1);
        if (uf.find(start - 1) == uf.find(end - 1)) {
            res = c;
            cout << res << "\n";
            break;
        }
    }
    return 0;
}