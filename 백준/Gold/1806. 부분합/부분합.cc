#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, s; cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int start = 0; int end = 0; int ans = 100002;
    int sum = 0;
    while (true)
    {
        if (sum >= s)
        {
            ans = min(ans, end - start);
            sum -= arr[start++];
        }
        else if (end == n) break;
        else sum += arr[end++];
    }
    if (ans == 100002) cout << 0;
    else cout << ans;
    return 0;
}