#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, start;
int dist[1001];
int INF = 1e9;
vector<pair<int, int>> graph[1001];
int prev_dist[1001];
void dijkstra(int s)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s] = 0;
    prev_dist[s] = -1;
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
                prev_dist[graph[here][i].first] = here;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int test_case = 0; test_case < t; test_case++)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back(make_pair(b, c));
            graph[b].push_back(make_pair(a, c));
        }
        fill(dist, dist + m, INF);
        fill(prev_dist, prev_dist + m, -1);
        dijkstra(0);
        if (dist[m - 1] == INF)
            cout << "Case #" << test_case + 1 << ": " << -1 << "\n";
        else
        {
            cout << "Case #" << test_case + 1 << ": ";
            vector<int> path;
            int cur = m - 1;
            while(cur != 0)
            {
                path.push_back(cur);
                cur = prev_dist[cur];
            }
            path.push_back(0);
            reverse(path.begin(), path.end());
            for (int i : path) cout << i << " ";
            cout << "\n";
        }
        for (int i = 0; i < m; i++)
        {
            graph[i].clear();
            prev_dist[i] = -1;
        }
    }
    return 0;
}