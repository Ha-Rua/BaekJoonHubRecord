#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1e9;
bool visited[101];
int dist[101];
void BFS(int start, const vector<pair<int, int>>& Edges)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == 100) break;
        for (int i = 1; i <= 6; i++)
        {
            int next = cur + i;
            for (pair<int, int> e : Edges)
            {
                if (e.first == next)
                {
                    next = e.second;
                    break;
                }
            }
            if (!visited[next])
            {
                visited[next] = true;
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }        
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < n + m; i++)
    {
        int a, b; cin >> a >> b;
        edges.push_back({a,b});
    }
    BFS(1, edges);
    cout << dist[100] << "\n";
    return 0;
}