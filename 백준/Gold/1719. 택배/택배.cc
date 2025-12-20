//problem number : 1719 (based on 11404 code)
#include <iostream>
using namespace std;
long long graph[201][201];
long long route[201][201];
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
        graph[a][b] = min(graph[a][b], c*1ll);
        route[a][b] = b;
        graph[b][a] = min(graph[b][a], c*1ll);
        route[b][a] = a;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) 
            {
                if (graph[i][j] > graph[i][k] + graph[k][j]) 
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    route[i][j] = route[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i==j) cout << '-' << " ";
            else cout << route[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}