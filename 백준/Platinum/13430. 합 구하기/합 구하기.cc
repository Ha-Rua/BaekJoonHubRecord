#include <iostream>
using namespace std;
using ll = long long;
ll m = 1000000007;
long long func1(ll n, ll k)
{
    ll res = 1;
    for (int i = 0; i < k; i++)
        res = (res * (n - i)) % m;
    return res % m;
}
long long func2(ll x, ll y, ll z)
{
    if (y == 1) return x % z;
    ll val = func2(x, y / 2, z);
    val = val * val % z;
    if (y % 2 == 1) val = val * x % z;
    return val % z;
}
int main()
{
    int n, k; cin >> n >> k;
    int N = n + k;
    int K = n + 1;
    cout << (func1(N, K) * func2(func1(K, K), m - 2, m)) % m;
    return 0;
}