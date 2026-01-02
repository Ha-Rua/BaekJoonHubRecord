#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s, k; cin >> s >> k;
    string res = "";
    for (char c : s)
    {
        res += c;
        if (c == *(k.end() - 1) && res.size() >= k.size())
        {
            if (res.substr(res.size() - k.size()) == k)
            {
                for (int i = 0; i < k.size(); i++)
                {
                    res.pop_back();
                }
            }
        }
    }
    cout << (res.empty() ? "FRULA" : res);
    return 0;
}