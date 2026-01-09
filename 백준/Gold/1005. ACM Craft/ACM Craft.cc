#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
vector<int> adj[1001];
int inDegree[1001];
int buildTime[1001];
int dp[1001];
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
    int t; cin >> t;
    while(t--)
    {
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
        {
            int d; cin >> d;
            buildTime[i] = d;
            dp[i] = d;
        }
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            inDegree[b]++;
        }
        topologicalSort();
        int w; cin >> w;
        cout << dp[w] << '\n';

        for(int i=1; i<=N; i++) 
        {
            adj[i].clear();
            inDegree[i] = 0;
            buildTime[i] = 0;
            dp[i] = 0;
        }
    }
    return 0;
}