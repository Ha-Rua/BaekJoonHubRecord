#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m; cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    vector<int> ans;
    int idxA = 0; 
    int idxB = 0; 
    while (true) {
        int maxVal = -1;
        int nextIdxA = -1;
        int nextIdxB = -1;
        for (int i = 100; i > 0; i--)
        {
            bool isInA = false;
            bool isInB = false;
            for (int j = idxA; j < n; j++) 
            {
                if(a[j] == i) 
                {
                    isInA = true;
                    nextIdxA = j;
                    break;
                }
            }
            for (int j = idxB; j < m; j++) 
            {
                if(b[j] == i)
                {
                    isInB = true;
                    nextIdxB = j;
                    break;
                }
            }
            if (isInA && isInB)
            {
                maxVal = i;
                break;
            }
            else
            {
                nextIdxA = -1;
                nextIdxB = -1;
            }
        }
        if (maxVal == -1) break;
        ans.push_back(maxVal);
        idxA = nextIdxA + 1;
        idxB = nextIdxB + 1;
    }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    return 0;
}