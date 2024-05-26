#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
int main() {
    long long A, B;
    cin >> A >> B;
    queue<pair<long long, int>> q;
    unordered_map<long long, int> visited;
    q.push({A, 1});
    visited[A] = 1;
    while (!q.empty()) {
        auto[current, steps] = q.front();
        q.pop();
        if (current == B) {
            cout << steps;
            return 0;
        }
        long long next1 = current * 2;
        long long next2 = current * 10 + 1;
        if (next1 <= B && visited.find(next1) == visited.end()) {
            q.push({next1, steps + 1});
            visited[next1] = steps + 1;
        }
        if (next2 <= B && visited.find(next2) == visited.end()) {
            q.push({next2, steps + 1});
            visited[next2] = steps + 1;
        }
    }
    cout << -1;
    return 0;
}