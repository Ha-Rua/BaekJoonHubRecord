//problem number : 21278 (based on 11404 code)
#include <iostream>
using namespace std;
long long graph[101][101];
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

    int ans1, ans2;
    long long min_dist = INF;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            long long total_dist = 0;
            for (int k = 1; k <= n; k++)
            {
                total_dist += min(graph[k][i], graph[k][j]);
            }
            if (total_dist < min_dist)
            {
                min_dist = total_dist;
                ans1 = i;
                ans2 = j;
            }
        }
    }
    cout << ans1 << " " << ans2 << " " << min_dist *2<< "\n";
    return 0;
}