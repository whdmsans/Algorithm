#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

int n, m, r;
int item[101];
int minDistance[101][101];

int sumCheck(int x, int y) {
    if (x == INF || y == INF) {
        return INF;
    } else {
        return x + y;
    }
}

// 14938번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b, l, cnt, result;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> item[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            minDistance[i][j] = INF;
            if (i == j) {
                minDistance[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        cin >> a >> b >> l;
        minDistance[a][b] = min(minDistance[a][b], l);
        minDistance[b][a] = minDistance[a][b];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 1; k <= n; k++) {
                if (i == k || j == k) {
                    continue;
                }
                minDistance[j][k] = min(minDistance[j][k], sumCheck(minDistance[j][i], minDistance[i][k]));
                minDistance[k][j] = minDistance[j][k];
            }
        }
    }
    result = 0;
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        for (int j = 0; j <= n; j++) {
            if (minDistance[i][j] <= m) {
                cnt += item[j];
            }
        }
        result = max(result, cnt);
    }
    cout << result;
    return 0;
}