#include <iostream>
using namespace std;
int graph[101][101];
int items[101];
int n, m, r;
#define INF 999999999
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) cin >> items[i];
    for (int i = 1; i <= n; i++)
    {
        fill(graph[i], graph[i] + n + 1, INF);
        graph[i][i] = 0;
    }
    for (int i = 1; i <= r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int cur = 0;
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] <= m) cur += items[j];
        }
        res = max(res, cur);
    }
    cout << res;
    return 0;
}