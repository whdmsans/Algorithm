#include <bits/stdc++.h>

using namespace std;

int arr[2187][2187];
int cnt[3] = {0, 0, 0};

void check(int size, int x, int y) {
    int i, j, xend, yend;
    xend = x + size;
    yend = y + size;
    for (i = x; i < xend; i++) {
        for (j = y; j < yend; j++) {
            if (i == x && j == y) {
                continue;
            } else if (j != y && arr[i][j] != arr[i][j - 1] || j == y && arr[i][y] != arr[i - 1][y]) {
                break;
            }
        }
        if (j != yend) {
            break;
        }
    }
    if (i == xend && j == yend) {
        cnt[arr[x][y] + 1]++;
    } else {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                check(size / 3, x + ((size / 3) * i), y + ((size / 3) * j));
            }
        }
    }
}


// 1780번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    check(n, 0, 0);
    for (int i = 0; i < 3; i++) {
        cout << cnt[i] << "\n";
    }
}