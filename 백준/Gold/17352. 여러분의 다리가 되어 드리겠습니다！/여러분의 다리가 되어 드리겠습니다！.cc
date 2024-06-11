#include <iostream>
using namespace std;
int arr[300001];
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) arr[i] = i;
    for (int i = 0; i < n - 2; i++)
    {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }
    cout << 1 << ' ';
    for (int i = 2; i <= n; i++)
    {
        if (findParents(1) != findParents(i))
        {
            cout << i;
            break;
        }
    }
    return 0;
}