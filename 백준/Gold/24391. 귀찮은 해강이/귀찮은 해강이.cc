#include <iostream>
#include <vector>
#include <set>
using namespace std;
class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (x == parent[x]) return x;
        else return parent[x] = find(parent[x]);
    }
    void unionSets(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) parent[a] = b;
            else if (rank[a] > rank[b]) parent[b] = a;
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
    int n, m; cin >> n >> m;
    UnionFind uf(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        uf.unionSets(a, b);
    }
    int res = 0;
    vector<int> arr(n);
    for (auto& i : arr) cin >> i;
    for (int i = 0; i < n - 1; i++) if (uf.find(arr[i]) != uf.find(arr[i + 1])) res++;
    cout << res;
    return 0;
}