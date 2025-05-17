#include <iostream>
using namespace std;
int main()
{
    int sum = 0;
    while(true)
    {
        int num;
        cin >> num;
        if (num == -1) break;
        else sum += num;
    }
    cout << sum;
    return 0;
}