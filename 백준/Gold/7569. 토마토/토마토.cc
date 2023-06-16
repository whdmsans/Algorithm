#include <bits/stdc++.h>

using namespace std;

struct tomato {
    int x, y, h;
};

int N, M, H, cnt;
tomato tmt;
int arr[100][100][100] = {0};
int visited[100][100][100] = {0};
int path[100][100][100] = {0};
queue<tomato> q;
int movingX[6] = {0, 0, -1, 1, 0, 0};
int movingY[6] = {-1, 1, 0, 0, 0, 0};
int movingH[6] = {0, 0, 0, 0, -1, 1};

void bfs() {
    cnt = 0;
    int x, y, h, mx, my, mh;
    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        h = q.front().h;
        q.pop();
        for (int i = 0; i < 6; i++) {
            mx = x + movingX[i];
            my = y + movingY[i];
            mh = h + movingH[i];
            if (mx < 0 || mx >= N || my < 0 || my >= M || mh < 0 || mh >= H) {
                continue;
            }
            if (arr[mh][mx][my] == 0 && visited[mh][mx][my] == 0) {
                visited[mh][mx][my] = 1;
                tmt.x = mx;
                tmt.y = my;
                tmt.h = mh;
                q.push(tmt);
                path[mh][mx][my] = path[h][x][y] + 1;
                cnt = max(cnt, path[mh][mx][my]);
            }
        }
    }
}

void check() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (visited[i][j][k] == 0) {
                    cnt = -1;
                    return;
                }
            }
        }
    }
}


// 7576번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> M;
    cin >> N;
    cin >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> arr[i][j][k];
                tmt.h = i;
                tmt.x = j;
                tmt.y = k;
                if (arr[i][j][k] == 1) {
                    visited[i][j][k] = 1;
                    q.push(tmt);
                } else if (arr[i][j][k] == -1) {
                    visited[i][j][k] = 1;
                }
            }
        }
    }
    bfs();
    check();
    cout << cnt;
}
