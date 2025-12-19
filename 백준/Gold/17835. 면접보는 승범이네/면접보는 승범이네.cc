//problem number : 17835 (based on 1753 code)
//multi source dijkstra
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k;
long long dist[100001];
long long INF = 1e18;
vector<pair<int, int>> graph[100001];
void dijkstra()
{
    priority_queue<pair<long long, int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != INF)
        {
            pq.push({-dist[i], i});
        }
    }
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
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[b].push_back(make_pair(a, c));
    }
    fill(dist, dist + n + 1, INF);
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        dist[a] = 0;
    }
    dijkstra();
    long long ans = 0;
    int idx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != INF && dist[i] > ans)
        {
            ans = dist[i];
            idx = i;
        }
    }
    cout << idx << "\n" << ans << "\n";
    return 0;
}