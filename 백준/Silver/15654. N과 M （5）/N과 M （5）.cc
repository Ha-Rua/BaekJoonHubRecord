#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int arr[10];
bool visited[10];
vector<int> numbers;

void dfs(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[cnt] = numbers[i - 1];
            dfs(cnt + 1);
            visited[i] = false; 
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int s; cin >> s;
        numbers.push_back(s);
    }
    sort(numbers.begin(), numbers.end());
    dfs(0);
    return 0;
}