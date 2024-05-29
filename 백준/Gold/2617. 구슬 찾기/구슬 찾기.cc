#include <iostream>
#include <vector>
#define MAX 101
#define INF 100000000

using namespace std;

int graph[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    int res = 0;
    int mid = (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        int rcount = 0;
        int ccount = 0;
        for (int j = 1; j <= n; j++) {
            if (i != j && graph[i][j] != INF) {
                rcount++;
            }
            if (i != j && graph[j][i] != INF) {
                ccount++;
            }
        }
        if (rcount >= mid || ccount >= mid) res++;
    }
    cout << res;
    return 0;
}