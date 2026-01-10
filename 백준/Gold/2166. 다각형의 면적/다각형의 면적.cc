#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
struct Point
{
    long long x, y;
};
int main()
{
    int n; cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++)
    {
        int X, Y; cin >> X >> Y;
        points[i].x = X; points[i].y = Y;
    }
    long long sumA = 0;
    long long sumB = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        sumA += points[i].x * points[j].y;
        sumB += points[i].y * points[j].x;
    }
    cout << fixed << setprecision(1) << abs(sumA - sumB) / 2.0;
    return 0;
}