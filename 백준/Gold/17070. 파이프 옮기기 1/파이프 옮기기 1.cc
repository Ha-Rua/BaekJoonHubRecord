#include <iostream>
using namespace std;
int board[17][17];
int n;
int ans = 0;
void DFS(int x, int y, int shape)
{
    if (x == n && y == n)
    {
        ans++;
        return;
    }
    if (shape == 0 || shape == 2)  if (y < n && !board[x][y + 1]) DFS(x, y + 1, 0);
    if (shape == 1 || shape == 2) if (x < n && !board[x + 1][y]) DFS(x + 1, y, 1);
    if (x < n && y < n) if (!board[x + 1][y] && !board[x][y + 1] && !board[x + 1][y + 1]) DFS(x + 1, y + 1, 2);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
    }
    DFS(1, 2, 0);
    cout << ans;
    return 0;
}