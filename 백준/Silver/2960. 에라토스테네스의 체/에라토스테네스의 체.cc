#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int arr[1001] = {0};
    int n, k; cin >> n >> k;
    int cnt = 0;
    int cur = 2;
    while (cnt < k) {
        for (int i = cur; i <= n; i += cur) {
            if (arr[i] == 0) {
                arr[i] = 1;
                cnt++;
                if (cnt == k) {
                    cout << i << "\n";
                    break;
                }
            }
        }
        cur++;
    }
    return 0;
}