#include <iostream>
#include <set>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        multiset<int> ms;
        for (int i = 0; i < n; i++)
        {
            char op; int x; cin >> op >> x;
            switch (op)
            {
                case 'I':
                    ms.insert(x);
                    break;
                case 'D':
                    if (!ms.empty()) {
                        if (x == 1) {
                            auto iter = ms.end();
                            iter--;
                            ms.erase(iter);
                        }
                        else {
                            ms.erase(ms.begin());
                        }
                    }
                    break;
            }
        }
        if (ms.empty()) {
                cout << "EMPTY\n";
            }
            else {
                auto iter = ms.end();
                iter--;
                cout << *iter << " " << *ms.begin() << "\n";
            }
    }
    return 0;
}