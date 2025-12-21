#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m, start;
long long dist[100001];
long long INF = 1e18;
vector<pair<int, int>> graph[100001];
void dijkstra(int s)
{
    priority_queue<pair<long long, int>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty())
    {
        long long cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (int i = 0; i < graph[here].size(); i++)
        {
            long long dis = cost + graph[here][i].second;
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
    int s1, s2, capital;
    cin >> s1 >> s2 >> capital;
    dijkstra(s1);
    long long dist1 = dist[capital];
    fill(dist, dist + n + 1, INF);
    dijkstra(s2);
    long long dist2 = dist[capital];
    cout << (dist1 <= dist2 ? "First\n" : "Second\n");
    return 0;
}