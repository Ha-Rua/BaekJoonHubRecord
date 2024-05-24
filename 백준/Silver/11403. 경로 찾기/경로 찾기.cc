#include <iostream>
using namespace std;
int graph[101][101];
int n;
#define INF 999999999
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) fill(graph[i], graph[i] + n + 1, INF);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x; cin >> x;
            if (x == 1) graph[i][j] = 1;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (graph[i][j] == INF ? 0 : 1) << ' ';
        }
        cout << '\n';
    }
    return 0;
}