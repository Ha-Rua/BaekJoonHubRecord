#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int parent[10000];
char command[10000];
bool visited[10000];
char commands[] = {'D', 'S', 'L', 'R'};
void DSLR(int start, int end) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == end) break;
        for (char cmd : commands) {
            int next;
            switch (cmd) {
                case 'D':
                    next = (cur * 2) % 10000;
                    break;
                case 'S':
                    next = (cur == 0) ? 9999 : cur - 1;
                    break;
                case 'L':
                    next = (cur % 1000) * 10 + (cur / 1000);
                    break;
                case 'R':
                    next = (cur % 10) * 1000 + (cur / 10);
                    break;
            }
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                command[next] = cmd;
                q.push(next);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int s, e; cin >> s >> e;
        DSLR(s, e);
        string result;
        for (int cur = e; cur != s; cur = parent[cur]) result += command[cur];
        reverse(result.begin(), result.end());
        cout << result << '\n';
        fill(visited, visited + 10000, false);
        fill(parent, parent + 10000, 0);
        fill(command, command + 10000, 0);
    } 
    
    return 0;
}