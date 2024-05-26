#include <iostream>
#include <deque>
#include <string>
#define INF 100000000
using namespace std;
int graph[101][101];
int dist[101][101]; 
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
deque<pair<int, int>> dq;
int n, m;
void zBFS();
int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, INF);
    zBFS();
    cout << dist[n - 1][m - 1];
    return 0;
}
void zBFS()
{
    dist[0][0] = 0;
    dq.push_back({0, 0});
    while (!dq.empty())
    {
        auto[x, y] = dq.front();
        dq.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] > dist[x][y] + graph[nx][ny])
            {
                dist[nx][ny] = dist[x][y] + graph[nx][ny];
                if (graph[nx][ny] == 0) dq.push_front({nx, ny});
                else dq.push_back({nx, ny});
            }
        }
    }
}