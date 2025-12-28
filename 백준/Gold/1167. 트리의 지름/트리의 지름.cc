#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, farthestNode;
int res = 0;
vector<pair<int, int>> graph[100001];
bool visited[100001];
int dist[100001];

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
    for (int i = 0; i < n; i++)
    {
        int u; cin >> u;
        while (true)
        {
            int v; cin >> v;
            if (v == -1) break;
            int w; cin >> w;
            graph[u].push_back({v, w});
        }
    }
    BFS(1);
    fill(visited, visited + 100001, false);
    fill(dist, dist + 100001, 0);
    res = 0;
    BFS(farthestNode);
    cout << res;
    return 0;
}