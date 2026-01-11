#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;
int N;
int W[16][16];
int dp[16][1 << 16];

int dfs(int curr, int visited) 
{
    if (visited == (1 << N) - 1) 
    {
        if (W[curr][0] != 0) return W[curr][0];
        else return INF;
    }

    if (dp[curr][visited] != -1) return dp[curr][visited];

    dp[curr][visited] = INF; 

    for (int next = 0; next < N; next++) 
    {
        if (W[curr][next] != 0 && (visited & (1 << next)) == 0)
        {
            int cost = W[curr][next] + dfs(next, visited | (1 << next));
            dp[curr][visited] = min(dp[curr][visited], cost);
        }
    }
    return dp[curr][visited];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            cin >> W[i][j];
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1) << '\n';

    return 0;
}