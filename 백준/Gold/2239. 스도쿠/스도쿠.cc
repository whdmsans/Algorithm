#include <bits/stdc++.h>

using namespace std;

string board[9];

bool row[9][9] = {false,};
bool col[9][9] = {false,};
bool square[3][3][9] = {false,};

bool func(int x, int y) {
    if (x == 9) {
        return true;
    }
    if (board[x][y] != '0') {
        return func(x + (y + 1) / 9, (y + 1) % 9);
    }
    for (int i = 0; i < 9; i++) {
        if (!row[x][i] && !col[y][i] && !square[x / 3][y / 3][i]) {
            row[x][i] = true;
            col[y][i] = true;
            square[x / 3][y / 3][i] = true;
            board[x][y] = (i + 1) + '0';
            if (func(x + (y + 1) / 9, (y + 1) % 9)) {
                return true;
            }
            row[x][i] = false;
            col[y][i] = false;
            square[x / 3][y / 3][i] = false;
            board[x][y] = 0 + '0';
        }
    }
    return false;
}

// 2239번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 9; i++) {
        cin >> board[i];
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '0') {
                row[i][board[i][j] - '1'] = true;
                col[j][board[i][j] - '1'] = true;
                square[i / 3][j / 3][board[i][j] - '1'] = true;
            }
        }
    }
    if (func(0, 0)) {
        for (int i = 0; i < 9; i++) {
            cout << board[i] << "\n";
        }
    }
    return 0;
}