#include <bits/stdc++.h>

using namespace std;

// 1074번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, r, c;
    long long cnt;
    cin >> N >> r >> c;
    cnt = 0;
    for (; N > 0;) {
        if (pow(2, N - 1) <= r) {
            r -= pow(2, N - 1);
            cnt += pow(2, N - 1) * pow(2, N);
        }
        if (pow(2, N - 1) <= c) {
            c -= pow(2, N - 1);
            cnt += pow(pow(2, N - 1), 2);
        }
        N--;
    }
    cout << cnt;
}
