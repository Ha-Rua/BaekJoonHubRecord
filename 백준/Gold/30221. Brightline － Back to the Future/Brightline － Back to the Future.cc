#include <iostream>
#include <vector>
const long long INF = 1e18;
using namespace std;
vector<int> ans;
struct Edge {
    int from, to, cost;
};
void Bellman_Ford(int n, int m, vector<Edge>& edges) {
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].from;
            int v = edges[j].to;
            int weight = edges[j].cost;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int u = edges[i].from;
        int v = edges[i].to;
        int weight = edges[i].cost;

        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            cout << -1;
            return;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (dist[i] < 0) ans.push_back(i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int s, e, a;
        char color;
        cin >> s >> e >> color >> a;
        edges[i] = {s, e, (color == 'b' ? a : -a)};
    }
    Bellman_Ford(n, m, edges);
    for (int node : ans) cout << node << "\n";
    return 0;
}