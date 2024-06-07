#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
    int n; cin >> n;
    unordered_map<int, int> a;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a[x]++;
    }
    int s = a.size();
    int res = 0;
    for (const auto& i : a) if (i.second > res) res = i.second;
    cout << res;
    return 0;
}