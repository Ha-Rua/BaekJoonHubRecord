#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    cout << fixed << setprecision(17);
    double ans = 1.0;
    double buf = 1.0;
    for (int i = 1; i <= n; i++) {
        buf *= i;
        ans += 1.0 / buf;
    }
    cout << ans;
    return 0;
}
