#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 2147483647;
int matrix[501][2];
int dp[501][501];
int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> matrix[i][0] >> matrix[i][1];
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}