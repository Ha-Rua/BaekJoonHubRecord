#include <iostream>
using namespace std;
using ll = long long;
ll m = 1000000007;
ll fact[4000001];
ll invFact[4000001];
long long power(ll x, ll y, ll z)
{
    if (y == 1) return x % z;
    ll val = power(x, y / 2, z);
    val = val * val % z;
    if (y % 2 == 1) val = val * x % z;
    return val % z;
}
void prepare()
{
    fact[0] = 1;
    for (int i = 1; i <= 4000001; i++) fact[i] = (fact[i - 1] * i) % m;
    invFact[4000000] = power(fact[4000000], m - 2, m) % m;
    for (int i = 3999999; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % m;
        }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    prepare();
    int t; cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;
        cout << (fact[n] * (invFact[k] * invFact[n - k] % m) % m) << '\n';
    }
    return 0;
}