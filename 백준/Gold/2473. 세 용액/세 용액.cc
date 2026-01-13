#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct Result {
    long long val;
    int a, b, c;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<long long> v;
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    Result best = {3000000001, 0, 0, 0};

    for (int i = 0; i < n - 2; i++) {
        int start = i + 1; 
        int end = n - 1; 

        while (start < end) {
            long long sum = v[i] + v[start] + v[end];

            if (abs(sum) < best.val) {
                best.val = abs(sum);
                best.a = v[i];
                best.b = v[start];
                best.c = v[end];
            }

            if (sum == 0) break;

            if (sum < 0) start++;
            else end--;
        }
    }

    cout << best.a << ' ' << best.b << ' ' << best.c;
    return 0;
}