#include <iostream>
using namespace std;
int arr[201];
int route[1001];
int findParents(int x)
{
    if (x == arr[x]) return x;
    else return arr[x] = findParents(arr[x]);
}
void unionParent(int a, int b)
{
    a = findParents(a); b = findParents(b);
    if (a < b) arr[b] = a;
    else arr[a] = b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) arr[i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x; cin >> x;
            if (x == 1) unionParent(i, j);
        }
    }
    for (int i = 0; i < m; i++) cin >> route[i];
    for (int i = 0; i < m - 1; i++)
    {
        if (findParents(route[i]) != findParents(route[i + 1]))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}