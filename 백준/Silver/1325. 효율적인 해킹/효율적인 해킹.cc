#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr[10001];
bool vis[10001];
int cnt[10001];
int res = 0;
void DFS(int n);
int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        DFS(i);
        cnt[i] = res;
        res = 0;
        fill(vis, vis + 10001, false);
    }
    int maxi = *max_element(cnt + 1, cnt + n + 1);
    for(int i = 1; i <= n; i++)
        if(cnt[i] == maxi) cout << i << " ";
    return 0;
}
void DFS(int n)
{
    if (vis[n]) return; 
    vis[n] = true;
    res++;
    for(int i = 0; i < arr[n].size(); i++)
    {
        int next = arr[n][i];
        if (!vis[next]) { 
            DFS(next);
        }
    }
}