#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, x;
int dist[1001];
int total_time[1001];
int INF = 100000000;
vector<pair<int, int>> graph1[1001];
vector<pair<int, int>> graph2[1001];
void dijkstra(int s, vector<pair<int, int>> graph[])
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
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph1[a].push_back(make_pair(b, c));
        graph2[b].push_back(make_pair(a, c));
    }
    fill(dist, dist + n + 1, INF);
    dijkstra(x, graph1);
    for (int i = 1; i <= n; i++)
        total_time[i] += dist[i];
    fill(dist, dist + n + 1, INF);
    dijkstra(x, graph2);
    for (int i = 1; i <= n; i++)
        total_time[i] += dist[i];
    int ans = -1;
    for (int i = 1; i <= n; i++)
        ans = (ans < total_time[i]) ? total_time[i] : ans;
    cout << ans;
    return 0;
}