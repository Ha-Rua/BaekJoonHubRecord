#include <iostream>
using namespace std;
int main()
{
    int a, b; cin >> a >> b;
    cout << 100 - a << ' ' << 100 - b << ' ';
    cout << a + b - 100 << ' ' << (100 - a) * (100 - b) << ' ';
    cout << ((100 - a) * (100 - b)) / 100 << ' ' << ((100 - a) * (100 - b)) % 100 << '\n';
    cout << a + b - 100 + ((100 - a) * (100 - b)) / 100 << ' ' << ((100 - a) * (100 - b)) % 100;
    return 0;
}