#include <iostream>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string str; cin >> str;
    string temp = "";
    bool isMinus = false;
    int res = 0;
    for (char c : str) {
        if (c == '+' || c == '-') {
            if (isMinus) {
                res -= stoi(temp);
            } else {
                res += stoi(temp);
            }
            temp = "";
            if (c == '-') {
                isMinus = true;
            }
        } else {
            temp += c;
        }
    }
    if (isMinus) {
        res -= stoi(temp);
    } else {
        res += stoi(temp);
    }
    cout << res << "\n";
    return 0;
}