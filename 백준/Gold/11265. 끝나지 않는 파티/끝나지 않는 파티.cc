#include <iostream>
using namespace std;
long long graph[501][501];
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int k; cin >> k;
            graph[i][j] = k;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        cout << (graph[a][b] <= c ? "Enjoy other party\n" : "Stay here\n");
    }
    return 0;
}