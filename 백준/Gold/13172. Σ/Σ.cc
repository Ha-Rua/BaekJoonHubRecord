#include <iostream>
using namespace std;
using ll = long long;
ll m = 1000000007;
int func(ll x, ll y, ll z)
{
    if (y == 1) return x % z;
    ll val = func(x, y / 2, z);
    val = val * val % z;
    if (y % 2 == 1) val = val * x % z;
    return val;
}
int main()
{
    int t; cin >> t;
    ll res = 0;
    while(t--)
    {
        ll n, s; cin >> n >> s;
        res += (s * func(n, m - 2, m)) % m;
    }
    cout << res % m;
    return 0;
}