#include <iostream>
using namespace std;
int acount = 0, bcount = 0;
int arr[128][128];
void func(int n, int m, int k)
{
    if (k == 1)
    {
        switch(arr[n][m])
        {
            case 0: acount++; break;
            case 1: bcount++; break;
        }
        return;
    }
    bool check = true;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (arr[n][m] != arr[n + i][m + j])
            {
                check = false;
                break;
            }
        }
        if (!check) break;
    }
    if (check)
    {
        switch(arr[n][m])
        {
            case 0: acount++; break;
            case 1: bcount++; break;;
        }
    }
    else
    {
        func(n, m, k / 2);
        func(n, m + (k / 2), k / 2);
        func(n + (k / 2), m, k / 2);
        func(n + (k / 2), m + (k / 2), k / 2);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    func(0, 0, n);
    cout << acount << '\n' << bcount;
}