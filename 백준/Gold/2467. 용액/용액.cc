#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int start = 0;
    int end = n - 1;
    int ans1 = v[0];
    int ans2 = v[n - 1];
    int minDiff = 2000000001;

    while (start < end)
    {
        int cur = v[start] + v[end];
        if (abs(cur) < minDiff)
        {
            minDiff = abs(cur);
            ans1 = v[start];
            ans2 = v[end];
        }
        if (cur == 0) break;
        if (cur < 0) start++;
        if (cur > 0) end--;
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}