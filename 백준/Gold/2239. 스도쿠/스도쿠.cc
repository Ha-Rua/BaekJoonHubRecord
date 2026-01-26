#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cstdlib>
using namespace std;
int board[9][9];
vector<pair<int, int>> zeros;
bool isPossible(int r, int c, int k)
{
    for (int i = 0; i < 9; i++)
    {
        if (i != r) if (board[i][c] == k) return false;
        if (i != c) if (board[r][i] == k) return false;
    }
    for (int i = (r / 3) * 3; i < (r / 3) * 3 + 3; i++)
    {
        for (int j = (c / 3) * 3; j < (c / 3) * 3 + 3; j++)
        {
            if (i == r && i == c) continue;
            if (board[i][j] == k) return false;
        }
    }
    return true;
}
void dfs(int n)
{
    if (n == zeros.size())
    {
        for (int i = 0; i < 9 ; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j];
            }
            cout << '\n';
        }
        exit(0);
    }
    
    int r = zeros[n].first;
    int c = zeros[n].second;

    for (int k = 1; k <= 9; k++)
    {
        if (isPossible(r, c, k))
        {
            board[r][c] = k;
            dfs(n + 1);
            board[r][c] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 9; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = s[j] - '0';
            if (board[i][j] == 0) zeros.push_back({i, j});
        }
    }
    dfs(0);
    return 0;
}