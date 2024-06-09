#include <iostream>
using namespace std;
int arr[500001];
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
    for (int i = 0; i < n; i++) arr[i] = i;
    int res = 1;
    bool cycle = false;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (findParents(a) == findParents(b))
        {
            cycle = true;
            break;
        }
        else unionParent(a, b);
        res++;
    }
    cout << (cycle ? res : 0);
    return 0;
}