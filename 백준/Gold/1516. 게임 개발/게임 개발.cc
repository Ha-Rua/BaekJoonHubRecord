#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
vector<int> adj[501];
int inDegree[501];
int buildTime[501];
int dp[501];
void topologicalSort() {
    queue<int> q;
    for (int i = 1; i <= N; i++) if (inDegree[i] == 0) q .push(i);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : adj[cur]) 
        {
            dp[next] = max(dp[next], dp[cur] + buildTime[next]);
            if (--inDegree[next] == 0)  q.push(next);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int d; cin >> d;
        buildTime[i] = d;
        dp[i] = d;
        while (true)
        {
            int k; cin >> k;
            if (k == -1) break;
            adj[k].push_back(i);
            inDegree[i]++;
        }
    }
    topologicalSort();
    for (int i = 1; i <= N; i++) cout << dp[i] << '\n';
    return 0;
}