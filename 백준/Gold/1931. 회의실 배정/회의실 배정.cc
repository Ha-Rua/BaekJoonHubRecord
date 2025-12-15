#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int, int>> meetings(n);
    for (int i = 0; i < n; ++i) {
        cin >> meetings[i].second >> meetings[i].first;
    }
    sort(meetings.begin(), meetings.end());
    int count = 0;
    int last_end_time = 0;
    for (const auto& meeting : meetings) {
        int s_time=meeting.second;
        int e_time=meeting.first;
        if (s_time >= last_end_time) {
            count++;
            last_end_time = e_time;
        }
    }
    cout << count << '\n';
    return 0;
}
