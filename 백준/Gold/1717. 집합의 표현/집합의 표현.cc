#include <iostream>
using namespace std;
int arr[1000001];
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
    for (int i = 0; i <= n; i++) arr[i] = i;
    for (int i = 0; i < m; i++)
    {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 0) unionParent(a, b);
        else if (k == 1)
        {
            if (findParents(a) == findParents(b)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}