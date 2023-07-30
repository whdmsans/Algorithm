#include <bits/stdc++.h>

using namespace std;

int R, C, T;
pair<int, int> ACP[2];
int moving[6] = {0, 0, 1, -1, 0, 0};
int room[50][50];
int temp[50][50];

void diffusion(int x, int y) {
    int dx, dy, cnt;
    cnt = 0;
    for (int i = 0; i < 4; i++) {
        dx = x + moving[i];
        dy = y + moving[i + 2];
        if (dx < 0 || dy < 0 || dx >= R || dy >= C || temp[dx][dy] == -1) {
            continue;
        }
        room[dx][dy] += temp[x][y] / 5;
        cnt++;
    }
    room[x][y] -= cnt * (temp[x][y] / 5);
}

void func() {
    int x, y, dx, dy;

    // up
    x = ACP[0].first;
    y = ACP[0].second;
    x--;
    dx = x - 1;
    dy = y;
    while (dx >= 0) {
        room[x][y] = room[dx][dy];
        x--;
        dx--;
    }
    dx = x;
    dy = y + 1;
    while (dy < C) {
        room[x][y] = room[dx][dy];
        y++;
        dy++;
    }
    dx = x + 1;
    dy = y;
    while (dx <= ACP[0].first) {
        room[x][y] = room[dx][dy];
        x++;
        dx++;
    }
    dx = x;
    dy = y - 1;
    while (dy >= 1) {
        room[x][y] = room[dx][dy];
        y--;
        dy--;
    }
    room[x][y] = 0;

    // down
    x = ACP[1].first;
    y = ACP[1].second;
    x++;
    dx = x + 1;
    dy = y;
    while (dx < R) {
        room[x][y] = room[dx][dy];
        x++;
        dx++;
    }
    dx = x;
    dy = y + 1;
    while (dy < C) {
        room[x][y] = room[dx][dy];
        y++;
        dy++;
    }
    dx = x - 1;
    dy = y;
    while (dx >= ACP[1].first) {
        room[x][y] = room[dx][dy];
        x--;
        dx--;
    }
    dx = x;
    dy = y - 1;
    while (dy >= 1) {
        room[x][y] = room[dx][dy];
        y--;
        dy--;
    }
    room[x][y] = 0;
}

// 17144번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int result = 0;
    cin >> R >> C >> T;
    int idx = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> room[i][j];
            if (room[i][j] == -1) {
                ACP[idx++] = make_pair(i, j);
            }
        }
    }
    while (T-- > 0) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                temp[i][j] = room[i][j];
            }
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (temp[i][j] > 0) {
                    diffusion(i, j);
                }
            }
        }
        func();
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            result += room[i][j];
        }
    }
    result += 2;
    cout << result;
    return 0;
}