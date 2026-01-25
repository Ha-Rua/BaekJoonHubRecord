#include <iostream>
#include <algorithm>
using namespace std;
int arr[2001];
bool dp[2001][2001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i][i] = true;
    }
    for (int i = 1; i < n; i++) if (arr[i] == arr[i + 1]) dp[i][i + 1] = true;
    for (int i = 2; i < n; i++) for (int j = 1; j <= n - i; j++) if ((arr[j] == arr[j + i]) && dp[j + 1][j + i - 1]) dp[j][j + i] = true;
    int m; cin >> m;
    while(m--)
    {
        int s, e; cin >> s >> e;
        cout << (dp[s][e] ? 1 : 0) << '\n';
    }
    return 0;
}