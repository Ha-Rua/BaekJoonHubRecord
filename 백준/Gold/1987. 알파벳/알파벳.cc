#include <iostream>
#include <string>
using namespace std;
int map[21][21];
bool vis[26];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans = 0;
int r, c;
void DFS(int x, int y, int cnt)
{
    ans = max(ans, cnt);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if (!vis[map[nx][ny]])
        {
            vis[map[nx][ny]] = true;
            DFS(nx, ny, cnt + 1);
            vis[map[nx][ny]] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < c; j++)
        {
            map[i][j] = s[j] - 'A';
        }
    }
    vis[map[0][0]] = true;
    DFS(0, 0, 1);
    cout << ans;
    return 0;
}   