#include <bits/stdc++.h>

using namespace std;

// 1676번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, i, j, cnt, max, c;
    cnt = 0;
    cin >> n;
    for (max = 5; max <= n; max *= 5) {}
    max /= 5;
    for (i = 5; i <= n; i += 5) {
        c = 0;
        for (j = max; i % j != 0; j /= 5) {}
        for (; j != 1; j /= 5) {
            c++;
        }
        cnt += c;
    }
    cout << cnt;
}