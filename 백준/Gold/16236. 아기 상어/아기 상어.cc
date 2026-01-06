#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int n;
int res = 0;
int arr[20][20];
int sharkSize = 2;
int eatCount = 0;
int sX, sY;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
struct Fih {
    int x, y, dist;
    bool operator<(const Fih& b) const {
        if (dist != b.dist) return dist < b.dist;
        if (x != b.x) return x < b.x; 
        return y < b.y; 
    }
};
Fih iGotcha()
{
    bool vis[20][20] = {false, };
    queue<pair<int, pair<int, int>>> q;
    vector<Fih> prey;
    q.push({0, {sX, sY}});
    vis[sX][sY] = true;
    while(!q.empty())
    {
        int dist = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (vis[nx][ny]) continue;
            if (arr[nx][ny] <= sharkSize)
            {
                vis[nx][ny] = true;
                q.push({dist + 1, {nx, ny}});
                if (arr[nx][ny] != 0 && arr[nx][ny] < sharkSize)
                    prey.push_back({nx, ny, dist + 1});
            }
        }
    }
    if (prey.empty()) return {-1, -1, -1};
    sort(prey.begin(), prey.end());
    return prey[0];
}
int main()
{
    ios::sync_with_stdio(false);    
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 9)
            {
                sX = i;
                sY = j;
                arr[i][j] = 0;
            }
        }
    }
    while(true)
    {
        Fih curPrey = iGotcha();
        if (curPrey.dist == -1) break;
        sX = curPrey.x;
        sY = curPrey.y;
        res += curPrey.dist;
        arr[sX][sY] = 0;
        eatCount += 1;
        if (eatCount == sharkSize)
        {
            sharkSize++;
            eatCount = 0;
        }
    }
    cout << res;
    return 0;
}