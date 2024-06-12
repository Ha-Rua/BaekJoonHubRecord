#include <iostream>
#include <map>
using namespace std;
int arr[1000001];
inline int findParent(int x)
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
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) arr[i] = i;
    for (int i = 1; i <= m; i++)
    {

        int a, b;
        cin >> a >> b;
        if (i == k) continue;
        unionParent(a, b);
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int x = findParent(i);
        mp[x]++;
    }
    long long res = 1;
    for (auto& x : mp) res *= x.second;
    if (res == n) res = 0;
    cout << res;
    return 0;
}