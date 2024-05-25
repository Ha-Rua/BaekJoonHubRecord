#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int graph[51][51];
int n;
#define INF 1e9
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        fill(graph[i], graph[i] + n + 1, INF);
        graph[i][i] = 0;
    }

    while (true)
    {
        int a, b; cin >> a >> b;
        if (a == -1 && b == -1) break;
        else 
        {
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
    vector<int> score(n + 1, 1e9);
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        int cur = 0;
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] > cur) cur = graph[i][j];
        }
        score[i] = cur;
    }
    int minnum = *min_element(score.begin() , score.end());
    int minper = 0;
    for (int i = 1; i <= n; i++)
    {
        if (score[i] == minnum)
        {
            minper++;
            res.push_back(i);
        }
    }
    cout << minnum << ' ' << minper << '\n';
    for (int a : res) cout << a << ' ';
    return 0;
}