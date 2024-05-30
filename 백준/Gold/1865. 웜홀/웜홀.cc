#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int from, to, cost;
};
void Bellman_Ford(int n, int m, vector<Edge>& edges) {
    vector<long long> dist(n + 1, 2000000000);
    dist[1] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].from;
            int v = edges[j].to;
            int weight = edges[j].cost;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i].from;
        int v = edges[i].to;
        int weight = edges[i].cost;

        if (dist[u] + weight < dist[v]) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while(tc--) {
        int n, m, w;
        cin >> n >> m >> w;
        vector<Edge> edges(2 * m + w);
        for (int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c;
            edges[i * 2].from = a;
            edges[i * 2].to = b;
            edges[i * 2].cost = c;
            edges[i * 2 + 1].from = b;
            edges[i * 2 + 1].to = a;
            edges[i * 2 + 1].cost = c;
        }
        for (int i = 0; i < w; i++) {
            cin >> edges[2 * m + i].from >> edges[2 * m + i].to >> edges[2 * m + i].cost;
            edges[2 * m + i].cost *= -1;
        }
        Bellman_Ford(n, 2 * m + w, edges);
    }
    return 0;
}