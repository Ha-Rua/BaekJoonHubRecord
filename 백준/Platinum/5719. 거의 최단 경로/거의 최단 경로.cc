#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, start;
int dist[501];
int INF = 1e9;
vector<pair<int, int>> graph[501];
vector<int> prev_dist[501];
bool is_deleted[501][501];
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
            int there = graph[here][i].first;
            if (is_deleted[here][there]) continue;
            int dis = cost + graph[here][i].second;
            if (dis < dist[there])
            {
                dist[there] = dis;
                prev_dist[there].clear();
                prev_dist[there].push_back(here);
                pq.push({-dis, there});
            }
            else if (dis == dist[there]) prev_dist[there].push_back(here);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;
        int s, d; cin >> s >> d;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back(make_pair(b, c));
        }
        fill(dist, dist + n + 1, INF);
        dijkstra(s);
        queue<int> q;
        q.push(d);
        while(!q.empty())
        {
            int here = q.front();
            q.pop();
            for (int i = 0; i < prev_dist[here].size(); i++)
            {
                int there = prev_dist[here][i];
                if (is_deleted[there][here]) continue;
                is_deleted[there][here] = true;
                q.push(there);
            }
        }
        fill(dist, dist + n + 1, INF);
        dijkstra(s);
        if (dist[d] == INF) cout << -1 << "\n";
        else cout << dist[d] << "\n";
        for (int i = 0; i <= n; i++)
        {
            graph[i].clear();
            prev_dist[i].clear();
            for (int j = 0; j <= n; j++) is_deleted[i][j] = false;
        }
    }
    return 0;
}