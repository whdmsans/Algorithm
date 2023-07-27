#include <bits/stdc++.h>

using namespace std;

// 1011번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    long long x, y;
    cin >> T;
    while (T-- > 0) {
        cin >> x >> y;
        long long max = 1;
        while (max * max <= y - x) {
            max++;
        }
        max--;
        long long time = 2 * max - 1;
        time += (y - x - max * max) / max;
        if ((y - x - max * max) % max > 0) {
            time++;
        }
        cout << time << "\n";
    }
}