#include <iostream>
#include <cmath>
using namespace std;
int col[15];
int ans = 0;
int n;
bool check(int x)
{
    for (int i = 0; i < x; i++)
        if (col[i] == col[x] || abs(col[i] - col[x]) == abs(i - x)) return false;
    return true;
}
void dfs(int x)
{
    for (int i = 0; i < n; i++)
    {
        col[x] = i;
        if (check(x)) 
        {
            if (x == n - 1)
            {
                ans++;
                continue;
            }
            dfs(x + 1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    dfs(0);
    cout << ans;
    return 0;
}