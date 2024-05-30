#include <iostream>
#include <deque>
#include <string>
#define INF 100000000
using namespace std;
int graph[301][301];
int dist[301][301]; 
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
deque<pair<int, int>> dq;
int n, m;
void BFS(int x, int y);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#') graph[i][j] = 1;
            else if (s[j] == '*') graph[i][j] = 0;
            else graph[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, INF);
    BFS(x1, y1);
    cout << dist[x2 - 1][y2 - 1];
    return 0;
}
void BFS(int x, int y)
{
    dist[x - 1][y - 1] = 0;
    dq.push_back({x - 1, y - 1});
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