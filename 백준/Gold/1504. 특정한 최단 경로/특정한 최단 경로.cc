#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, start;
int dist[801];
int INF = 100000000;
vector<pair<int, int>> graph[801];
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
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    fill(dist, dist + n + 1, INF);
    int v1, v2; cin >> v1 >> v2;
    int d1 = 0;
    int d2 = 0;
    dijkstra(1);
    d1 += dist[v1];
    d2 += dist[v2];
    fill(dist, dist + n + 1, INF);
    dijkstra(v1);
    d1 += dist[v2];
    d2 += dist[n];
    fill(dist, dist + n + 1, INF);
    dijkstra(v2);
    d1 += dist[n];
    d2 += dist[v1];
    cout << (d1 >= INF && d2 >= INF ? -1 : min(d1, d2));
    return 0;
}