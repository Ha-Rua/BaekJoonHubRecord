#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool visited1[1001];
bool visited2[1001];
vector<int> graph[1001];
void DFS(int v) {
    visited1[v] = true;
    cout << v << ' ';
    for (int i = 0; i < graph[v].size(); i++) {
        if (!visited1[graph[v][i]]) {
            DFS(graph[v][i]);
        }
    }
};
void BFS(int v) {
    queue<int> q;
    q.push(v);
    visited2[v] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << ' ';
        for (int i = 0; i < graph[u].size(); i++) {
            if (!visited2[graph[u][i]]) {
                q.push(graph[u][i]);
                visited2[graph[u][i]] = true;
            }
        }
    }
};
int main() {
    int n, m, v;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) 
        sort(graph[i].begin(), graph[i].end());
    DFS(v);
    cout << '\n';
    BFS(v);
    return 0;
}