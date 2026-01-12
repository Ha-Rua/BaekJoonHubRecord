#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

vector<double> radiusList;
double INF = 1e9;
int N;
double d;
double dist[16][16];
double dp[16][1 << 16];

double getDist(double r1, double r2)
{
    double x = d - r1 - r2;
    double l = r1 + r2;
    return (sqrt(pow(l, 2) - pow(x, 2)));
}

double dfs(int curr, int visited) 
{
    if (visited == (1 << N) - 1)  return radiusList[curr];

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

    while (true)
    {
        cin >> N >> d;
        if (N == 0 && d == 0) break;
        
        radiusList.clear();
        for (int i = 0; i < N; i++)
        {
            double m; cin >> m;
            radiusList.push_back(m);
        }

        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < N; j++) {
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = getDist(radiusList[i], radiusList[j]);
            }
        }

        for(int i = 0; i < N; i++) for(int j = 0; j < (1 << N); j++) dp[i][j] = -1.0;

        double ans = -1;
        for (int i = 0; i < N; i++)
        {
            double total = radiusList[i] + dfs(i, 1 << i);
            if (ans == -1 || total < ans) ans = total;
        }

        cout << (int)round(ans) << '\n';

    }
    return 0;
}