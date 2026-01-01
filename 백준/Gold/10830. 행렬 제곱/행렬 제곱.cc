#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long>> Matrix;
long long n;
Matrix multiply(Matrix a, Matrix b)
{
    Matrix c(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000;
        }
    }
    return c;
}
Matrix Power(Matrix a, long long N)
{
    if (N == 1) return a;
    Matrix m = Power(a, N / 2);
    m = multiply(m, m);
    if (N % 2 == 1)
    {
        m = multiply(m, a);
    }
    return m;
}
int main()  
{
    long long m; cin >> n >> m;
    Matrix M(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }
    M = Power(M, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << M[i][j] % 1000 << ' ';
        }
        cout << '\n';
    }
    return 0;
}