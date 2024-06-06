#include <iostream>
#include <string>
using namespace std;
int graph[1002][1002];
int main()
{
    string s1, s2; cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                graph[i][j] = graph[i - 1][j - 1] + 1;
            }
            else
            {
                graph[i][j] = max(graph[i - 1][j], graph[i][j - 1]);
            }
        }
    }
    cout << graph[n][m];
    return 0;
}