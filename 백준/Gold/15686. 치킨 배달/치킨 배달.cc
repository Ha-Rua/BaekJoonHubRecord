#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct Coord {
    int x, y;
};
int n, m;
int result = 2147483647;
vector<Coord> house;
vector<Coord> chicken;
bool selected[13];
void DFS(int idx, int count)
{
    if (count == m)
    {
        int cur_res = 0;
        for (int i = 0; i < house.size(); i++)
        {
            vector<int> dist;
            for (int j = 0; j < chicken.size(); j++)
            {
                if (selected[j])
                {
                    dist.push_back(abs(house[i].x - chicken[j].x) + abs(house[i].y - chicken[j].y));
                }
            }
            cur_res += *min_element(dist.begin(), dist.end());
        }
        result = min(result, cur_res);
    }
    else
    {
        for (int i = idx; i < chicken.size(); i++)
        {
            if(!selected[i])
            {
                selected[i] = true;
                DFS(i + 1, count + 1);
                selected[i] = false;
            }

        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t; cin >> t;
            if (t == 1) house.push_back({i, j});
            else if (t == 2) chicken.push_back({i, j});
        }
    }
    DFS(0, 0);
    cout << result;
    return 0;
}