#include <iostream>
#include <string>
using namespace std;
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    string str; cin >> str;
    int error_count = 0;
    int sum = 0;
    for (int i = 0; i < 13; i++) {
        if (str[i] == '*') error_count = i;
        else sum += (i % 2 == 1 ? (str[i] - '0') * 3 : (str[i] - '0'));
    }
    for (int i = 0; i < 10; i++) {
        int total = sum + (error_count % 2 == 1 ? i * 3 : i);
        if (total % 10 == 0) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}