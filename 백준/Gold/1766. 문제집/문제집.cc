#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
vector<int> adj[32001];
int inDegree[32001];
void topologicalSort() {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= N; i++) if (inDegree[i] == 0) q .push(i);
    while (!q.empty()) {
        int cur = q.top();
        q.pop();
        cout << cur << " "; 
        for (int next : adj[cur]) if (--inDegree[next] == 0)  q.push(next);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        inDegree[b]++;
    }
    topologicalSort();
    return 0;
}