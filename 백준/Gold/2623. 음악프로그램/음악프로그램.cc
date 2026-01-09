#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> adj[32001];
int inDegree[32001];
void topologicalSort() {
    vector<int> res;
    queue<int> q;
    for (int i = 1; i <= N; i++) if (inDegree[i] == 0) q .push(i);
    for (int i = 1; i <= N; i++)
    {
        if (q.empty())
        {
            cout << 0 << '\n';
            return;
        }
        int x = q.front();
        q.pop();
        res.push_back(x);
        for (auto next : adj[x]) if (--inDegree[next] == 0) q.push(next);
    }
    for (auto i : res) cout << i << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int k; cin >> k;
        vector<int> temp;
        for (int j = 0; j < k; j++)
        {
            int p; cin >> p;
            temp.push_back(p);
        }
        for (int j = 0; j < k - 1; j++)
        {
            adj[temp[j]].push_back(temp[j + 1]);
            inDegree[temp[j + 1]]++;
        }
    }
    topologicalSort();
    return 0;
}