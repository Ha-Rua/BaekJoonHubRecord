#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

struct Pos
{
    int x, y, z;
};
Pos start;
vector<Pos> people;
const int INF = 1e18;
int F, W, L, N;
long long dist[16][16];
long long dp[16][1 << 16];

long long getDist(Pos p1, Pos p2)
{
    if (p1.z == p2.z) return abs(p1.x - p2.x) + abs(p1.y - p2.y);
    long long vDist = (p1.z < p2.z ? (long long)((p2.z - p1.z) * 2) : (long long)(p1.z - p2.z));
    long long minDist = -1;
    int nx[4] = {1, 1, W, W};
    int ny[4] = {1, L, 1, L};
    for (int i = 0; i < 4; i++)
    {
        long long d1 = abs(p1.x - nx[i]) + abs(p1.y - ny[i]);
        long long d2 = abs(p2.x - nx[i]) + abs(p2.y - ny[i]);
        long long totalDist = d1 + vDist + d2;
        if (minDist == -1 || totalDist < minDist) minDist = totalDist;
    }
    return minDist;
}

long long dfs(int curr, int visited) 
{
    if (visited == (1 << N) - 1) return 0;

    if (dp[curr][visited] != -1) return dp[curr][visited];

    dp[curr][visited] = INF; 

    for (int next = 0; next < N; next++) {
        if ((visited & (1 << next)) == 0)
        {
            long long cost = dist[curr][next] + dfs(next, visited | (1 << next));
            dp[curr][visited] = min(dp[curr][visited], cost);
        }
    }
    return dp[curr][visited];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        cin >> F >> W >> L >> N;
        cin >> start.z >> start.x >> start.y;
        people.clear();
        for (int i = 0; i < N; i++)
        {
            Pos p; cin >> p.z >> p.x >> p.y;
            people.push_back(p);
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j) dist[i][j] = 0;
                dist[i][j] = getDist(people[i], people[j]);
            }
        }
        memset(dp, -1, sizeof(dp));
        long long res = -1;
        for (int i = 0; i < N; i++)
        {
            long long startDist = getDist(start, people[i]);
            long long total = startDist + dfs(i, 1 << i);
            if (res == -1 || total < res) res = total;
        }
        cout << res << '\n';
    }
    return 0;
}