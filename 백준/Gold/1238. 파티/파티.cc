#include <iostream>
using namespace std;
int graph[1001][1001];
int n, m, x;
#define INF 100000000
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> x;

    for (int i = 1; i <= n; i++)
    {
        fill(graph[i], graph[i] + n + 1, INF);
        graph[i][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
    int max = -1;
    for (int i = 1; i <= n; i++)
    {
        int cur = graph[i][x] + graph[x][i];
        if (max < cur) max = cur;
    }
    cout << max;
    return 0;
}