#include <iostream>
#include <vector>
using namespace std;

char board[3072][6144];

void draw(int n, int x, int y) {
    if (n == 3) {
        board[x][y] = '*';
        board[x + 1][y - 1] = '*';
        board[x + 1][y + 1] = '*';
        for (int i = -2; i < 3; i++) board[x + 2][y + i] = '*';
        return;
    }

    int half = n / 2;
    draw(half, x, y);
    draw(half, x + half, y - half);
    draw(half, x + half, y + half);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            board[i][j] = ' ';
        }
    }

    draw(n, 0, n - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}