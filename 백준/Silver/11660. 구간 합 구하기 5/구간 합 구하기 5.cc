#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x; cin >> x;
            if (i == 0 && j == 0) v[i][j] = x;
            else if (i == 0) v[i][j] = v[i][j - 1] + x;
            else if (j == 0) v[i][j] = v[i - 1][j] + x;
            else v[i][j] = v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1] + x;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        i1--; j1--; i2--; j2--;
        if (i1 == 0 && j1 == 0) cout << v[i2][j2] << '\n';
        else if (i1 == 0) cout << v[i2][j2] - v[i2][j1 - 1] << '\n';
        else if (j1 == 0) cout << v[i2][j2] - v[i1 - 1][j2] << '\n';
        else cout << v[i2][j2] - v[i2][j1 - 1] - v[i1 - 1][j2] + v[i1 - 1][j1 - 1] << '\n';
    }
}