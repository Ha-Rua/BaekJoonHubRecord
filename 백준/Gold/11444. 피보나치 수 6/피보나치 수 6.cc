#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long>> Matrix;
Matrix multiply(Matrix a, Matrix b)
{
    Matrix c(2, vector<long long>(2));
    c[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % 1000000007;
    c[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % 1000000007;
    c[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % 1000000007;
    c[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % 1000000007;
    return c;
}
Matrix Power(Matrix a, long long N)
{
    if (N == 1) return a;
    Matrix m = Power(a, N / 2);
    m = multiply(m, m);
    if (N % 2 == 1)
    {
        Matrix temp = {{1, 1}, {1, 0}};
        m = multiply(m, temp);
    }
    return m;
}
int main()
{
    long long n; cin >> n;
    Matrix res = {{1, 1}, {1, 0}};
    res = Power(res, n);
    cout << res[0][1];
    return 0;
}