#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

int N, M;
int moving[6] = {0, 0, 1, -1, 0, 0};
string input;
int board[2][1001][1001];

struct cell {
    int x, y, w;

    cell(int x, int y, int wall) : x(x), y(y), w(wall) {}
};

int bfs() {
    board[0][N - 1][M - 1] = -1;
    board[1][N - 1][M - 1] = -1;

    int x, y, w, dx, dy;
    queue<cell> q;
    q.push(cell(0, 0, 1));
    board[1][0][0] = 1;

    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        w = q.front().w;
        q.pop();
        for (int i = 0; i < 4; i++) {
            dx = x + moving[i];
            dy = y + moving[i + 2];
            if (dx < 0 || dy < 0 || dx >= N || dy >= M) {
                continue;
            }
            if (w == 1) {
                if (!(dx == 0 && dy == 0) && board[w][dx][dy] == 1) {
                    q.push(cell(dx, dy, 0));
                    board[0][dx][dy] = board[1][x][y] + 1;
                } else if (board[w][dx][dy] <= 0) {
                    q.push(cell(dx, dy, 1));
                    board[1][dx][dy] = board[1][x][y] + 1;
                }
            } else if (board[w][dx][dy] <= 0) {
                q.push(cell(dx, dy, w));
                board[w][dx][dy] = board[w][x][y] + 1;
            }
        }
    }
    if (board[0][N - 1][M - 1] != -1 && board[1][N - 1][M - 1] != -1) {
        return min(board[0][N - 1][M - 1], board[1][N - 1][M - 1]);
    } else if (board[0][N - 1][M - 1] != -1) {
        return board[0][N - 1][M - 1];
    } else if (board[1][N - 1][M - 1] != -1) {
        return board[1][N - 1][M - 1];
    } else {
        return -1;
    }
}

// 2206번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int result = INF;
    int a;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            board[0][i][j] = input[j] - '0';
            board[1][i][j] = board[0][i][j];
        }
    }

    cout << bfs();

    return 0;
}