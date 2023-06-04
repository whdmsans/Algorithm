#include <bits/stdc++.h>

using namespace std;

int N;
string arr[64];
string result = "";

void compress(int size, int fx, int fy) {
    int x = fx, y = fy, i = 0;
    for (i = 0; i < size * size; i++) {
        if (y != fy && arr[x][y] != arr[x][y - 1] ||
            y == fy && x != fx && arr[x][y] != arr[x - 1][y]) {
            result += "(";
            compress(size / 2, fx, fy);
            compress(size / 2, fx, fy + (size / 2));
            compress(size / 2, fx + (size / 2), fy);
            compress(size / 2, fx + (size / 2), fy + (size / 2));
            result += ")";
            break;
        }
        y++;
        if (y >= fy + size) {
            x++;
            y = fy;
        }
    }
    if (i == size * size) {
        result += arr[fx][fy];
    }
}

// 1992번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    compress(N, 0, 0);
    cout << result;
}
