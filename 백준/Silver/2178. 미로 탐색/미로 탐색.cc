#include <iostream>
#include <utility>
#include <queue>
#include <string>
using namespace std;
int graph[100][100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int n, m;
int BFS(int x, int y);
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            graph[i][j] = s.at(j) - '0';
        }
    }
    cout << BFS(0, 0);
    return 0;
}
int BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int da = a + dx[i];
            int db = b + dy[i];
            if(da < 0 || db < 0 || da >= n || db >= m) continue;
            if(graph[da][db] == 0) continue;
            if(graph[da][db] == 1)
            {
                graph[da][db] = graph[a][b] + 1;
                q.push({da, db});
            }
        }
    }
    return graph[n-1][m-1];
}