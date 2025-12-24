#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        string prompt; cin >> prompt;
        int n; cin >> n;
        deque<int> arr;
        string s; cin >> s;
        string temp = "";
        for (char ch : s) {
            if (ch == '[' || ch == ']' ) continue;
            else if (ch == ',') {
                arr.push_back(stoi(temp));
                temp = "";
            } 
            else temp += ch;
        }
        if (!temp.empty()) arr.push_back(stoi(temp));
        bool isReversed = false;
        bool isError = false;
        for (char ch : prompt) {
            if (ch == 'R') {
                isReversed = !isReversed;
            } 
            else if (ch == 'D') {
                if (arr.empty()) {
                    isError = true;
                    break;
                } 
                else {
                    if (isReversed) arr.pop_back();
                    else arr.pop_front();
                }
            }
        }
        if (isError) {
            cout << "error\n";
        } else {
            cout << "[";
            while (!arr.empty()) {
                if (isReversed) {
                    cout << arr.back();
                    arr.pop_back();
                } else {
                    cout << arr.front();
                    arr.pop_front();
                }
                if (!arr.empty()) cout << ",";
            }
            cout << "]\n";
        }
    }
    return 0;
}