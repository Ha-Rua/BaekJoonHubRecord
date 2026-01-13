#include <iostream>
#include <cstring>
using namespace std;

int nextNode[100001];
bool vis[100001];
bool fin[100001];
int cycleCount;

void dfs(int cur)
{
    vis[cur] = true;
    int next = nextNode[cur];

    if (!vis[next]) dfs(next);
    else if (!fin[next])
    {
        for (int i = next; i != cur; i = nextNode[i]) cycleCount++;
        cycleCount++;
    }
    fin[cur] = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        memset(vis, 0, sizeof(bool) * (n + 1));
        memset(fin, 0, sizeof(bool) * (n + 1));
        cycleCount = 0;
        for (int i = 1; i <= n; i++) cin >> nextNode[i];
        for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
        cout << n - cycleCount << '\n';
    }
    return 0;
}