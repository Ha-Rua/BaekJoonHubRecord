#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
struct jewel
{
    int m, v;
};

bool cmp(const jewel& a, const jewel& b)
{
    return a.v > b.v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;

    vector<jewel> jewels(n);
    for (int i = 0; i < n; i++) cin >> jewels[i].m >> jewels[i].v;

    multiset<int> bags;
    for (int i = 0; i < k; i++)
    {
        int a; cin >> a;
        bags.insert(a);
    }
    sort(jewels.begin(), jewels.end(), cmp);

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (bags.empty()) break;

        auto it = bags.lower_bound(jewels[i].m);

        if (it != bags.end())
        {
            ans += jewels[i].v;
            bags.erase(it);
        }
    }
    cout << ans;
    return 0;
}