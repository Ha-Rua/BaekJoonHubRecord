#include <iostream>
#include <vector>
using namespace std;
vector<int> arr[101];
int vis[101];
void DFS(int n);
int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            arr[i + 1].push_back(a);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            DFS(i);
        }
    }
    int cnt1 = 0, cnt2 = 0;
    vector<int> group1, group2;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1)
        {
            cnt1++;
            group1.push_back(i);
        }
        else if (vis[i] == 2)
        {
            cnt2++;
            group2.push_back(i);
        }
    }
    cout << cnt1 << "\n";
    for (auto g1 : group1) cout << g1 << " ";
    cout << "\n" << cnt2 << "\n";
    for (auto g2 : group2) cout << g2 << " ";
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
    }
}