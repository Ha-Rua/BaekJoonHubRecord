#include <queue>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int BFS(int a, int b, int c, vector<vector<int>> g, queue<pair<int, int>> q);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    queue<pair<int, int>> q;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
    {
        graph[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            int x; cin >> x;
            if (x == 2) q.push({i, j});
            graph[i][j] = x;
        }
    }
    int res = 0;
    for (int i = 0; i < n * m - 2; i++)
    {
        if (graph[i / m][i % m] != 0) continue;
        for (int j = i + 1; j < n * m - 1; j++)
        {
            if (graph[j / m][j % m] != 0) continue;
            for (int k = j + 1; k < n * m; k++)
            {
                if (graph[k / m][k % m] != 0) continue;
                int cur = BFS(i, j, k, graph, q);
                if (res < cur) res = cur;
            }
        }
    }
    cout << res;
    return 0;
}
int BFS(int a, int b, int c, vector<vector<int>> g, queue<pair<int, int>> q)
{
    g[a / m][a % m] = 1;
    g[b / m][b % m] = 1;
    g[c / m][c % m] = 1;
    while (!q.empty())
    {
        auto[x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (g[nx][ny] == 0)
            {
                g[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 0) cnt++;
        }
    }
    return cnt;
}   