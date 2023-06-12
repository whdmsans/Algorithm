#include <bits/stdc++.h>

using namespace std;

int N, M, px, py;
int arr[1000][1000] = {0};
int visited[1000][1000] = {0};
int moving[6] = {0, 0, 1, -1, 0, 0};

void bfs(int x, int y) {
    visited[x][y] = 1;
    arr[x][y] = 0;
    int mx, my;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            mx = x + moving[i];
            my = y + moving[i + 2];
            if (mx < 0 || my < 0 || mx >= N || my >= M) {
                continue;
            }
            if (visited[mx][my] == 1) {
                if (arr[mx][my] + 1 < arr[x][y]) {
                    arr[x][y] = arr[mx][my] + 1;
                }
                continue;
            }
            if (arr[mx][my] == 1) {
                visited[mx][my] = 1;
                q.push(make_pair(mx, my));
                arr[mx][my] = 2001;
            }
        }
    }
}

// 14940번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                px = i;
                py = j;
            }
        }
    }
    bfs(px, py);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0 && arr[i][j] == 1) {
                cout << "-1 ";
            } else {
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
