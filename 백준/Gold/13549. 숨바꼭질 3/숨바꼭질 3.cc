#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, start;
int dist[200001];
int INF = 2147483647;
vector<pair<int, int>> graph[200001];
void dijkstra(int s)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        if (graph[here].empty())
        {
            if (here < 200000) graph[here].push_back({here + 1, 1});
            if (here > 0) graph[here].push_back({here - 1, 1});
            if (here <= 100000) graph[here].push_back({here * 2, 0});
        }
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
    fill(dist, dist + 200000, INF);
    dijkstra(n);
    cout << dist[m];
    return 0;
}