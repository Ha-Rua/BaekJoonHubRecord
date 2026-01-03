#include <iostream>
#include <vector>
using namespace std;
int n, m;
int arr[71];
void dfs(int cnt, int start)
{
    if (cnt == m + 1)
    {
        for (int i = 1; i <= m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = start; i <= n; i++) {
        arr[cnt] = i;
        dfs(cnt + 1, i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    dfs(1, 1);
    return 0;
}