#include <iostream>
#include <vector>
using namespace std;
vector<int> arr[2001];
int vis[2001];
bool isBipartite = true;
void DFS(int n);
int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int k, n, m;
    cin >> k;
    for (int t = 0; t < k; t++)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            arr[i].clear();
            vis[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                DFS(i);
            }
        }
        cout << "Scenario #" << t + 1 << ":\n";
        if (!isBipartite)
            cout << "Suspicious bugs found!\n";
        else
            cout << "No suspicious bugs found!\n";
        cout << "\n";
        isBipartite = true;
    }
    return 0;
}
void DFS(int n)
{
    for(int next : arr[n])
    {
        if (!vis[next])
        {
            vis[next] = 3 - vis[n];
            DFS(next);
        }
        else if (vis[next] == vis[n])
        {
            isBipartite = false;
            return;
        }
    }
}