#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, start;
int dist[10001];
int INF = 2147483647;
vector<pair<int, int>> graph[10001];
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
    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> start;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            graph[b].push_back(make_pair(a, c));
        }
        fill(dist, dist + n + 1, INF);
        dijkstra(start);
        int num = 0, maxcost = -1;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] < INF) num++;
            if (maxcost < dist[i] && dist[i] < INF)
            {
                maxcost = dist[i];
            }
        }
        cout << num << " " << maxcost << "\n";
        for (int i = 1; i <= n; i++) graph[i].clear();
    }
    return 0;
}