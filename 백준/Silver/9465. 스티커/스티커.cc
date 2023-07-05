#include <bits/stdc++.h>

using namespace std;

int T, n;
int arr[2][100000];

// 9465번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int x, y, dx;
    cin >> T;
    while (T-- > 0) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[0][i];
        }
        for (int i = 0; i < n; i++) {
            cin >> arr[1][i];
        }
        arr[0][1] += arr[1][0];
        arr[1][1] += arr[0][0];

        for (int i = 4; i < 2 * n; i++) {
            x = i % 2;
            y = i / 2;
            dx = (i - 1) % 2;
            arr[x][y] += max(max(arr[x][y - 2], arr[dx][y - 2]), arr[dx][y - 1]);
        }

        cout << max(max(arr[0][n - 1], arr[1][n - 1]), max(arr[0][n - 2], arr[1][n - 2])) << "\n";
    }
}
