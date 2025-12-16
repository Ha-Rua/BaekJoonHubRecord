#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    char arr[101][101];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int h_count = 0;
    int v_count = 0;
    for (int i = 0; i < n; i++) {
        int h_temp = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '.') h_temp++;
            else {
                if (h_temp >= 2) h_count++;
                h_temp = 0;
            }
        }
        if (h_temp >= 2) h_count++;
    }
    for (int i = 0; i < n; i++) {
        int v_temp = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == '.') v_temp++;
            else {
                if (v_temp >= 2) v_count++;
                v_temp = 0;
            }
        }
        if (v_temp >= 2) v_count++;
    }
    cout << h_count << " " << v_count << "\n";
    return 0;
}
