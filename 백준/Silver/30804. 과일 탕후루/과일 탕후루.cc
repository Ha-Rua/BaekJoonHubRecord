#include <iostream>
using namespace std;
int arr[200001];
int cnt[10] = {0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int max_len = 0;
    int left = 0, right = 0;
    int kind_count = 0;
    while(right < n) {
        if (cnt[arr[right]] == 0) kind_count++;
        cnt[arr[right]]++;
        right++;
        while (kind_count > 2) {
            cnt[arr[left]]--;
            if (cnt[arr[left]] == 0) kind_count--;
            left++;
        }
        max_len = max(max_len, right - left);
    }
    cout << max_len << "\n";
    return 0;
}