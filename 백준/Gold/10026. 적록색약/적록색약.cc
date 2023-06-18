#include <bits/stdc++.h>

using namespace std;

int N;
string arr[100];
int visited1[100][100] = {0};
int visited2[100][100] = {0};
int moving[6] = {0, 0, -1, 1, 0, 0};

void dfs1(int x, int y) {
    int mx, my;
    visited1[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        mx = x + moving[i];
        my = y + moving[i + 2];
        if (mx < 0 || my < 0 || mx >= N || my >= N) {
            continue;
        }
        if (visited1[mx][my] == 1) {
            continue;
        }
        if (arr[x][y] == arr[mx][my]) {
            dfs1(mx, my);
        }
    }
}

void dfs2(int x, int y) {
    int mx, my;
    visited2[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        mx = x + moving[i];
        my = y + moving[i + 2];
        if (mx < 0 || my < 0 || mx >= N || my >= N) {
            continue;
        }
        if (visited2[mx][my] == 1) {
            continue;
        }
        if (arr[x][y] == arr[mx][my] || arr[x][y] != 'B' && arr[mx][my] != 'B') {
            dfs2(mx, my);
        }
    }
}

// 10026번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    int cnt1, cnt2;
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited1[i][j] == 0) {
                dfs1(i, j);
                cnt1++;
            }
            if (visited2[i][j] == 0) {
                dfs2(i, j);
                cnt2++;
            }
        }
    }
    cout << cnt1 << " " << cnt2 << "\n";
}
