#include <bits/stdc++.h>

using namespace std;

int DP[1000001];

// 1463번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int x, min;
    cin >> x;
    DP[1] = 0;
    for (int i = 2; i <= x; i++) {
        min = DP[i - 1];
        if (i % 3 == 0 && min > DP[i / 3]) {
            min = DP[i / 3];
        }
        if (i % 2 == 0 && min > DP[i / 2]) {
            min = DP[i / 2];
        }
        DP[i] = min + 1;
    }
//    for (int i = 2; i <= x; i++) {
//        DP[i] = DP[i - 1] + 1;
//        if (i % 3 == 0) {
//            DP[i] = min(DP[i / 3] + 1, DP[i]);
//        }
//        if (i % 2 == 0) {
//            DP[i] = min(DP[i / 2] + 1, DP[i]);
//        }
//    }
    cout << DP[x];
}