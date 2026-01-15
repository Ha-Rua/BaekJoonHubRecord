#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1002][1002];
int main()
{
    string s1, s2; cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m] << '\n';
    string ans = "";
    while(n > 0 && m > 0)
    {
        if (dp[n - 1][m] == dp[n][m]) n--;
        else if (dp[n][m - 1] == dp[n][m]) m--;
        else if (dp[n - 1][m - 1] == dp[n][m] - 1)
        {
            ans += s1[n - 1];
            n--;
            m--;
        }
    }
    if (!ans.empty())
    {
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    return 0;
}