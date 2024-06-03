#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int graph[200001];
int main()
{
    int a, b; cin >> a >> b;
    queue<int> q;
    q.push(a);
    while(!q.empty())
    {
        graph[a] = 1;
        int now = q.front();
        q.pop();
        for (int next : {now + 1, now - 1, now * 2})
        {
            if (next < 0 || next >= 200001) continue;
            if (graph[next] == 0)
            {
                q.push(next);
                graph[next] = graph[now] + 1;
            }
        }
    }
    cout << graph[b] - 1 << '\n';
    vector<int> res;
    res.push_back(b);
    while (a != b)
    {
        if (graph[b + 1] == graph[b] - 1) b++;
        else if (graph[b - 1] == graph[b] - 1) b--;
        else if (b % 2 == 0 && graph[b / 2] == graph[b] - 1) b /= 2;
        res.push_back(b);
    }
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << ' ';
    return 0;
}