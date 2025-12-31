#include <iostream>
#include <tuple>
#include <queue>
#include <string>
using namespace std;
int graph[1000][1000];
int vis[1000][1000][2];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int n, m;
int BFS();
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            graph[i][j] = s.at(j) - '0';
        }
    }
    cout << BFS();
    return 0;
}
int BFS() {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    vis[0][0][0] = 1;
    while (!q.empty()) {
        int a = get<0>(q.front());
        int b = get<1>(q.front());
        int k = get<2>(q.front());
        q.pop();
        if (a == n - 1 && b == m - 1) return vis[a][b][k];
        for (int i = 0; i < 4; i++)
        {
            int da = a + dx[i];
            int db = b + dy[i];
            if (da < 0 || db < 0 || da >= n || db >= m) continue;
            if (graph[da][db] == 1)
            {
                if (k == 0)
                {
                    vis[da][db][1] = vis[a][b][k] + 1;
                    q.push({da, db, 1});
                }
            }
            if (graph[da][db] == 0)
            {
                if (vis[da][db][k] == 0)
                {
                    vis[da][db][k] = vis[a][b][k] + 1;
                    q.push({da, db, k});
                }
            }
        }
    }
    return -1;
}