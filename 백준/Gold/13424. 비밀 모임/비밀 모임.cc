#include <iostream>
using namespace std;
long long graph[401][401];
int n, m;
#define INF 1e18
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
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
            graph[b][a] = min(graph[b][a], c*1ll);
        }

        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
        int q; cin >> q;
        int member[q];
        long long ans = 0;
        int ans_idx = -1;
        for (int i = 0; i < q; i++) cin >> member[i];
        for (int i = 1; i <= n; i++)
        {
            long long temp = 0;
            for (int j = 0; j < q; j++) temp += graph[i][member[j]];
            if (i == 1 || temp < ans)
            {
                ans = temp;
                ans_idx = i;
            }
        }
        cout << ans_idx << '\n';
    }
    return 0;
}