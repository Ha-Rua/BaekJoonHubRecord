#include <iostream>
#include <vector>
using namespace std;
int arr[51];
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
    int k; cin >> k;
    vector<int> know(k);
    for (int i = 0; i < k; i++) cin >> know[i];
    for (int i = 0; i < n; i++) arr[i] = i;
    int res = 0;
    vector<vector<int>> list(m, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        list[i].resize(x);
        for (int j = 0; j < x; j++) cin >> list[i][j];
        for (int j = 0; j < x - 1; j++) unionParent(list[i][j], list[i][j + 1]); 
    }
    for (int i = 0; i < m; i++)
    {
        int s = list[i].size();
        bool check = true;
        for (int j = 0; j < s; j++)
        {
            for (int l = 0; l < k; l++)
            {
                if (findParents(list[i][j]) == findParents(know[l]))
                {
                    check = false;
                    break;
                }
            }
            if (!check) break;
        }
        if (check) res++;
    }
    cout << res;
    return 0;
}