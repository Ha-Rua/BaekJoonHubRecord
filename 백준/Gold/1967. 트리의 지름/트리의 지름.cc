#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, farthestNode;
int res = 0;
vector<pair<int, int>> graph[10001];
bool visited[10001];
int dist[10001];

void BFS(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    dist[v] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto next : graph[u]) {
            if (!visited[next.first]) {
                q.push(next.first);
                visited[next.first] = true;
                dist[next.first] = dist[u] + next.second;
                if (dist[next.first] > res)
                {
                    res = dist[next.first];
                    farthestNode = next.first;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    BFS(1);
    fill(visited, visited + 10001, false);
    fill(dist, dist + 10001, 0);
    res = 0;
    BFS(farthestNode);
    cout << res;
    return 0;
}