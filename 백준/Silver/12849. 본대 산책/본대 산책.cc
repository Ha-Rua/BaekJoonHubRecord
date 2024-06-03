#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> graph = {{1, 2}, {0, 2, 3}, {0, 1, 3, 4}, {1, 2, 4, 5}, {2, 3, 5, 6}, {3, 4, 7}, {4, 7}, {5, 6}};
    vector<vector<long long>> routes = {{1},{0},{0},{0},{0},{0},{0},{0}};
    int d; cin >> d;
    for (int i = 0; i < 8; i++) routes[i].resize(d + 1);
    for (int i = 1; i <= d; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            long long cur = 0;
            for (int k = 0; k < graph[j].size(); k++)
            {
                cur += routes[graph[j][k]][i - 1];
            }
            routes[j][i] = cur % 1000000007;
        }
    }
    cout << routes[0][d];
    return 0;
}