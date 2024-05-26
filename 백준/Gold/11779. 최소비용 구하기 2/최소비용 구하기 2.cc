#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, start;
int dist[1001];
int INF = 2147483647;
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
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }
    fill(dist, dist + n + 1, INF);
    cin >> start;
    int end; cin >> end;
    dijkstra(start);
    cout << dist[end] << '\n';
    int count = 0, h = end;
    vector<int> res;
    while (h != -1)
    {
        count++;
        res.push_back(h);
        h = prev_dist[h];
    }
    reverse(res.begin(), res.end());
    cout << count << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}