#include <bits/stdc++.h>

using namespace std;

int N, result;
int board[15][15] = {0};

bool checkPlace(int x, int y) {
    for (int i = 0; i < N; i++) {
        if (i < x && board[i][y] == 1) {
            return false;
        }
        if (x - i >= 0 && y - i >= 0 && board[x - i][y - i] == 1) {
            return false;
        }
        if (x - i >= 0 && y + i < N && board[x - i][y + i] == 1) {
            return false;
        }
    }
    return true;
}

void dfs(int line) {
    if (line == N) {
        result++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (checkPlace(line, i)) {
            board[line][i] = 1;
            dfs(line + 1);
            board[line][i] = 0;
        }
    }
}

// 9963번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    result = 0;
    dfs(0);
    cout << result;
}
