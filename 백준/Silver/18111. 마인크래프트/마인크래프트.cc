#include <bits/stdc++.h>

using namespace std;

// 18111번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, b, cnt, min, maxHigh;
    long long sum;
    cin >> n >> m >> b;
    int a[n][m];
    sum = b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    sum = sum / (n * m);
    if (sum > 256) {
        sum = 256;
    }
    min = 64000000;
    for (int h = 0; h <= sum; h++) {
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] > h) {
                    cnt += ((a[i][j] - h) * 2);
                } else if (a[i][j] < h) {
                    cnt += (h - a[i][j]);
                }
            }
        }
        if (min >= cnt) {
            min = cnt;
            maxHigh = h;
        }
    }
    cout << min << " " << maxHigh;
}