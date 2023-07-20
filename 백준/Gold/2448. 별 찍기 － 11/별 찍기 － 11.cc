#include <bits/stdc++.h>

using namespace std;

int N;
string board[3072];

void basicTriangle(int x) {
    board[x] += "  *   ";
    board[x + 1] += " * *  ";
    board[x + 2] += "***** ";
}

void func(int x, int n) {
    if (n == 3) {
        basicTriangle(x);
        return;
    }
    int halfN = n / 2;
    for (int i = x; i < x + halfN; i++) {
        for (int j = 0; j < halfN; j++) {
            board[i] += " ";
        }
    }
    func(x, halfN);
    func(x + halfN, halfN);
    func(x + halfN, halfN);
    for (int i = x; i < x + halfN; i++) {
        for (int j = 0; j < halfN; j++) {
            board[i] += " ";
        }
    }
    return;
}

// 2448번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    fill_n(board, 3072, "");

    func(0, N);

    for (int i = 0; i < N; i++) {
        cout << board[i] << "\n";
    }
}
