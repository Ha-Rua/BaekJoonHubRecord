#include <iostream>
using namespace std;
int arr[1000001];
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
    for (int w = 1; w <= t; w++)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n; i++) arr[i] = i;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            unionParent(a, b);
        }
        int k; cin >> k;
        cout << "Scenario " << w << ":\n";
        for (int i = 0; i < k; i++)
        {
            int a, b; cin >> a >> b;
            cout << (findParent(a) == findParent(b) ? 1 : 0) << '\n';
        }
        cout << '\n';
    }
    return 0;
}