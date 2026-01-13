#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[4000], B[4000], C[4000], D[4000];

vector<int> AB, CD;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
    AB.reserve(n * n);
    CD.reserve(n * n);
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<n; j++) 
        {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(CD.begin(), CD.end());

    long long ans = 0;

    for (int a : AB)
    {
        int k = -a;
        auto start = lower_bound(CD.begin(), CD.end(), k);
        auto end = upper_bound(CD.begin(), CD.end(), k);
        ans += (end - start);
    }

    cout << ans;
    return 0;
}