//problem number : 6054 (based on 1753 code)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int dist[1001];
int L_time[1001];
int INF = 1e9;
vector<pair<int, int>> graph[1001];
void dijkstra(int s)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (int i = 0; i < graph[here].size(); i++)
        {
            int dis = cost + graph[here][i].second;
            if (dis < dist[graph[here][i].first])
            {
                dist[graph[here][i].first] = dis;
                pq.push({-dis, graph[here][i].first});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, m;
        cin >> l >> m;
        L_time[i + 1] = l;
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            graph[i + 1].push_back({t, L_time[i + 1]});
        }
    }
    fill(dist, dist + n + 1, INF);
    dijkstra(1);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dist[i]+L_time[i]);
    cout << ans << "\n";
    return 0;
}