#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        vector<int> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        sort(s.begin(), s.end());
        int start = 1, end = s[n - 1] - s[0];
        int res = 0;
        while (start <= end)
        {
            int router = 1;
            int mid = (start + end) / 2;
            int cur = s[0];
            for (int i = 1; i < n; i++)
            {
                if (s[i] - cur >= mid)
                {
                    router++;
                    cur = s[i];
                }
            }
            if (router >= m)
            {
                res = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        cout << res << '\n';
    }
    return 0;
}