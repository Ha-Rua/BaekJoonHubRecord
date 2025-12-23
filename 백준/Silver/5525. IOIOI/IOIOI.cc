#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    int count = 0;
    int IOI_count = 0;
    for (int i = 0; i < m - 1; i++)
    {
        if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
            IOI_count++;
            if (IOI_count == n) {
                count++;
                IOI_count--;
            }
            i++;
        } else {
            IOI_count = 0;
        }
    }
    cout << count;
    return 0;
}