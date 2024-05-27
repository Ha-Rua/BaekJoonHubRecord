#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long graph[201][201];
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
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
    int k; cin >> k;
    vector<int> cities(n);
    vector<int> rescity;
    for (int i = 0; i < k; i++) cin >> cities[i];
    long long res = 2 * INF;
    for (int i = 1; i <= n; i++)
    {
        long long maxdis = -1;
        for (int j = 0; j < k; j++)
        {
            maxdis = max(graph[i][cities[j]] + graph[cities[j]][i], maxdis);
        }
        if (maxdis < res)
        {
            res = maxdis;
            rescity.clear();
            rescity.push_back(i);
        }
        else if (maxdis == res)
        {
            rescity.push_back(i);
        }
    }
    sort(rescity.begin(), rescity.end());
    for (int i : rescity) cout << i << " ";
    return 0;
}