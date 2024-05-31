#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int INF = 2000000000;
void dijkstra(int s, vector<int>& dist, vector<vector<pair<int, int>>>& graph)
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
    int tc; cin >> tc;
    while(tc--)
    {
        int n, m, start, t, g, h;
        cin >> n >> m >> t >> start >> g >> h;
        vector<int> distS(n + 1, INF);
        vector<int> distG(n + 1, INF);
        vector<int> distH(n + 1, INF);
        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].emplace_back(make_pair(b, c));
            graph[b].emplace_back(make_pair(a, c));
        }
        vector<int> lis(t);
        for (int& i : lis) cin >> i;
        dijkstra(start, distS, graph);
        dijkstra(g, distG, graph);
        dijkstra(h, distH, graph);
        vector<int> res;
        for (int i : lis)
        {
            if (distS[i] == INF) continue;
            int cur = min(distS[g] + distG[h] + distH[i], distS[h] + distH[g] + distG[i]);
            if (cur == distS[i]) res.emplace_back(i);
        }
        sort(res.begin(), res.end());
        for (int i : res) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}