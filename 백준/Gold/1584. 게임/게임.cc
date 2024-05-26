#include <iostream>
#include <deque>
#define INF 100000000
using namespace std;
int graph[501][501];
int dist[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void BFS()
{
    deque<pair<int, int>> dq;
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
            if (nx < 0 || nx > 500 || ny < 0 || ny > 500) continue;
            if (graph[nx][ny] == -1) continue;
            if (dist[nx][ny] > dist[x][y] + graph[nx][ny])
            {
                dist[nx][ny] = dist[x][y] + graph[nx][ny];
                if (graph[nx][ny] == 0) dq.push_front({nx, ny});
                else if (graph[nx][ny] == 1) dq.push_back({nx, ny});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        for (int j = x1; j <= x2; j++)
        {
            for (int k = y1; k <= y2; k++)
            {
                graph[j][k] = 1;
            }
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        for (int j = x1; j <= x2; j++)
        {
            for (int k = y1; k <= y2; k++)
            {
                graph[j][k] = -1;
            }
        }
    }
    for (int i = 0; i <= 500; i++)
        fill(dist[i], dist[i] + 501, INF);
    BFS();
    cout << (dist[500][500] == INF ? -1 : dist[500][500]);
    return 0;
}