#include <iostream>
using namespace std;
int graph[101][101];
int n, m;
#define INF 1e9
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        fill(graph[i], graph[i] + n + 1, INF);
        graph[i][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
    int min = 2147483647;
    int res = 500;
    for (int i = n; i >= 1; i--)
    {
        int cur = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            cur += graph[i][j];
        }
        if (cur <= min)
        {
            min = cur;
            res = i;
        }
    }
    cout << res;
    return 0;
}