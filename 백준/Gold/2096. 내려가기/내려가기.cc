#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n; cin >> n;
    int max_dp[3] = {0, };
    int min_dp[3] = {0, };
    int input[3];
    for (int i = 0; i < n; i++)
    {
        cin >> input[0] >> input[1] >> input[2];
        if (i == 0)
        {
            max_dp[0] = min_dp[0] = input[0];
            max_dp[1] = min_dp[1] = input[1];
            max_dp[2] = min_dp[2] = input[2];
            continue;
        }
        int temp0 = max(max_dp[0], max_dp[1]) + input[0];
        int temp1 = max({max_dp[0], max_dp[1], max_dp[2]}) + input[1];
        int temp2 = max(max_dp[1], max_dp[2]) + input[2];

        max_dp[0] = temp0;
        max_dp[1] = temp1;
        max_dp[2] = temp2;

        temp0 = min(min_dp[0], min_dp[1]) + input[0];
        temp1 = min({min_dp[0], min_dp[1], min_dp[2]}) + input[1];
        temp2 = min(min_dp[1], min_dp[2]) + input[2];

        min_dp[0] = temp0;
        min_dp[1] = temp1;
        min_dp[2] = temp2;
    }
    cout << max({max_dp[0], max_dp[1], max_dp[2]}) << ' ' << min({min_dp[0], min_dp[1], min_dp[2]});
    return 0;
}