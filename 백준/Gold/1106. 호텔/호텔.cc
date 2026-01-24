#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
int dp[2000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 2000; i++) dp[i] = INF;
    int c, n; cin >> c >> n;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int cost, people; cin >> cost >> people;
        for (int j = people; j < c + 101; j++) dp[j] = min(dp[j], dp[j - people] + cost);
    }
    int ans = INF;
    for (int i = c; i < c + 101;  i++) ans = min(ans, dp[i]);
    cout << ans;
    return 0;
}