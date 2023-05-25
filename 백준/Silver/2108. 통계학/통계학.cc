#include <bits/stdc++.h>

using namespace std;

// 2108번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int avg = 0;
    int n, cnt;
    pair<int, float> max;
    cin >> n;
    int num[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        avg += num[i];
    }
    if (round((double) avg / n) == -0) {
        avg = 0;
    }
    cout << round((double) avg / n) << "\n";

    sort(num, num + n);
    cout << num[n / 2] << "\n";

    cnt = 1;
    max.first = num[0];
    max.second = 0;
    num[n] = num[n - 1] + 1;
    for (int i = 1; i < n + 1; i++) {
        if (num[i] == num[i - 1]) {
            cnt++;
            continue;
        }
        if (max.second < cnt) {
            max.second = cnt;
            max.first = num[i - 1];
        } else if (max.second == cnt) {
            max.second += 0.5;
            max.first = num[i - 1];
        }
        cnt = 1;
    }
    cout << max.first << "\n";

    cout << num[n - 1] - num[0];
}