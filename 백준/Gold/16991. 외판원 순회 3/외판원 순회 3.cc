#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

struct Pos { int x, y; };
vector<Pos> posList;
double INF = 1e9;
int N;
double dist[16][16];
double dp[16][1 << 16];

double getDist(Pos p1, Pos p2) { return sqrt(pow(abs(p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2)); }

double dfs(int curr, int visited) 
{
    if (visited == (1 << N) - 1) return dist[curr][0];

    if (dp[curr][visited] != -1) return dp[curr][visited];

    dp[curr][visited] = INF; 

    for (int next = 0; next < N; next++) {
        if ((visited & (1 << next)) == 0)
        {
            double cost = dist[curr][next] + dfs(next, visited | (1 << next));
            dp[curr][visited] = min(dp[curr][visited], cost);
        }
    }
    return dp[curr][visited];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >>  N;
    for (int i = 0; i < N; i++)
    {
        Pos p; cin >> p.x >> p.y;
        posList.push_back(p);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j) dist[i][j] = 0;
            dist[i][j] = getDist(posList[i], posList[j]);
        }
    }
    for (int i = 0; i < 16; i++) for (int j = 0; j < (1 << 16); j++) dp[i][j] = -1.0;
    cout << fixed << setprecision(6) << dfs(0, 1) << '\n';
    return 0;
}