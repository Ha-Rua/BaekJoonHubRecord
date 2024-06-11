#include <iostream>
#include <utility>
#include <cmath>
#include <set>
using namespace std;
int arr[3001];
pair<pair<int, int>, int> info[3001];
int findParent(int x)
{
    if (x == arr[x]) return x;
    else return arr[x] = findParent(arr[x]);
}
void unionParent(int a, int b)
{
    a = findParent(a); b = findParent(b);
    if (a < b) arr[b] = a;
    else arr[a] = b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) arr[i] = i;
        for (int i = 1; i <= n; i++)
        {
            cin >> info[i].first.first >> info[i].first.second >> info[i].second;
            for (int j = 1; j < i; j++)
            {
                int dx = pow(abs(info[i].first.first - info[j].first.first), 2);
                int dy = pow(abs(info[i].first.second - info[j].first.second), 2);
                int dr = pow(info[i].second + info[j].second, 2);
                int dist = dx + dy;
                if (dist <= dr) unionParent(i, j);
            }
        }
        set<int> s;
        for (int i = 1; i <= n; i++) s.insert(findParent(i));
        cout << s.size() << '\n';
    }
    return 0;
}