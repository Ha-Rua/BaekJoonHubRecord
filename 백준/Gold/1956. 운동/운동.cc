#include <iostream>
using namespace std;
long long graph[401][401];
int n, m;
#define INF 1e18
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
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
    long long min = INF + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            if (min > graph[i][j] + graph[j][i]) min = graph[i][j] + graph[j][i];
        }
    }
    cout << (min == INF + 1 ? -1 : min);
    return 0;
}