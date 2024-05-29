#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Edge {
    int from, to, cost;
};
void Bellman_Ford(int n, int m, vector<Edge>& edges) {
    vector<long long> dist(n + 1, INT_MAX);
    dist[1] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].from;
            int v = edges[j].to;
            int weight = edges[j].cost;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int u = edges[i].from;
        int v = edges[i].to;
        int weight = edges[i].cost;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << -1;
            return;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            cout << -1 << '\n';
        } else {
            cout << dist[i] << '\n';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }
    
    Bellman_Ford(n, m, edges);
    return 0;
}