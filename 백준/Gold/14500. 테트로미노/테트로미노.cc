#include <bits/stdc++.h>

using namespace std;

int N, M;
int board[500][500];
int moving[6] = {0, 0, -1, 1, 0, 0};
int visited[500][500] = {0};

int getMax(int x, int y, int c, int cnt) {
    visited[x][y] = 1;
    cnt += board[x][y];
    int result = cnt;
    c++;
    if (c == 4) {
        visited[x][y] = 0;
        return result;
    }
    int mx, my;
    for (int i = 0; i < 4; i++) {
        mx = x + moving[i];
        my = y + moving[i + 2];
        if (mx < 0 || my < 0 || mx >= N || my >= M) {
            continue;
        }
        if (visited[mx][my] != 0) {
            continue;
        }
        result = max(result, getMax(mx, my, c, cnt));
    }
    if (c == 2) {
        int mx1, my1;
        for (int i = 0; i < 4; i++) {
            mx = x + moving[i];
            my = y + moving[i + 2];
            if (mx < 0 || my < 0 || mx >= N || my >= M) {
                continue;
            }
            if (visited[mx][my] != 0) {
                continue;
            }
            cnt += board[mx][my];
            visited[mx][my] = 1;
            for (int j = 0; j < 4; j++) {
                mx1 = x + moving[j];
                my1 = y + moving[j + 2];
                if (mx1 < 0 || my1 < 0 || mx1 >= N || my1 >= M) {
                    continue;
                }
                if (visited[mx1][my1] != 0) {
                    continue;
                }
                cnt += board[mx1][my1];
                visited[mx1][my1] = 1;
                result = max(result, cnt);
                cnt -= board[mx1][my1];
                visited[mx1][my1] = 0;
            }
            cnt -= board[mx][my];
            visited[mx][my] = 0;
        }
    }
    visited[x][y] = 0;
    return result;
}

// 14500번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int cnt = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cnt = max(cnt, getMax(i, j, 0, 0));
        }
    }
    cout << cnt;
}
