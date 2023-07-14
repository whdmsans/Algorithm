#include <bits/stdc++.h>

using namespace std;

int N, result;
int arr[17][17] = {0};

void func(int x, int y, int t) {
    if (x == N && y == N) {
        result++;
    }
    if (t != 3 && y + 1 <= N && arr[x][y + 1] != 1) {
        func(x, y + 1, 1);
    }
    if (y + 1 <= N && x + 1 <= N && arr[x][y + 1] != 1 && arr[x + 1][y + 1] != 1 && arr[x + 1][y] != 1) {
        func(x + 1, y + 1, 2);
    }
    if (t != 1 && x + 1 <= N && arr[x + 1][y] != 1) {
        func(x + 1, y, 3);
    }
}

// 17070번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    func(1, 2, 1);
    cout << result << "\n";
}
