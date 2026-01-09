#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> adj[32001];
int inDegree[32001];
void topologicalSort() {
    queue<int> q;
    for (int i = 1; i <= N; i++) if (inDegree[i] == 0) q .push(i);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " "; 
        for (int next : adj[cur]) if (--inDegree[next] == 0)  q.push(next);
    }
}
int main() {
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