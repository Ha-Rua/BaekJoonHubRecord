#include <iostream>
#include <queue>
using namespace std;
int graph[200001];
int routes[200001];
int main()
{
    int a, b; cin >> a >> b;
    queue<int> q;
    q.push(a);
    while(!q.empty())
    {
        graph[a] = 1;
        routes[a] = 1;
        int now = q.front();
        q.pop();
        for (int next : {now + 1, now - 1, now * 2})
        {
            if (next < 0 || next >= 200001) continue;
            if (graph[next] == 0)
            {
                q.push(next);
                graph[next] = graph[now] + 1;
                routes[next] = routes[now];
            }
            else if (graph[next] == graph[now] + 1)
            {
                routes[next] += routes[now];
            }
        }
    }
    cout << graph[b] - 1 << '\n' << routes[b];
    return 0;
}