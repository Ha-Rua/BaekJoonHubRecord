#include <iostream>
using namespace std;
int dp[101][100001];
int weight[100001];
int value[1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> weight[i] >> value[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (weight[i] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    cout << dp[n][k];
    return 0;
}