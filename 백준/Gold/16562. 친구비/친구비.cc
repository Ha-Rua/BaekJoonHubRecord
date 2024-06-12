#include <iostream>
#include <map>
using namespace std;
int arr[10001];
int money[10001];
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
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) arr[i] = i;
    for (int i = 1; i <= n; i++) cin >> money[i];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }
    map<int, int> minmoney;
    for (int i = 1; i <= n; i++)
    {
        int cur = findParent(i);
        if (minmoney.find(cur) == minmoney.end() || minmoney[cur] > money[i]) minmoney[cur] = money[i];
    }
    int res = 0;
    for (auto& cost : minmoney) res += cost.second;
    cout << (res > k ? "Oh no" : to_string(res));
    return 0;
}