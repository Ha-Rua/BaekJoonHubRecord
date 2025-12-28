#include <iostream>
#include <queue>
using namespace std;

int n;
vector<int> graph[100001];
int parent[100001];
bool visited[100001];

void BFS(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            if (!visited[graph[u][i]]) {
                q.push(graph[u][i]);
                visited[graph[u][i]] = true;
                parent[graph[u][i]] = u;
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
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    BFS(1);
    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';
}