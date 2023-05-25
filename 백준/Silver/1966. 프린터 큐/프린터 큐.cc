#include <bits/stdc++.h>

using namespace std;

// 1966번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, n, m, i, j, cnt;
    int p[100];
    queue<pair<int, int>> queue1;
    cin >> t;
    for (i = 0; i < t; i++) {
        cnt = 1;
        cin >> n >> m;
        for (j = 0; j < n; j++) {
            cin >> p[j];
            queue1.push(make_pair(j, p[j]));
        }
        sort(p, p + n);
        for (; !queue1.empty();) {
            if (queue1.front().second == p[n - cnt]) {
                if (queue1.front().first == m) {
                    cout << cnt << "\n";
                    break;
                }
                queue1.pop();
                cnt++;
            } else {
                queue1.push(queue1.front());
                queue1.pop();
            }
        }
        for (; !queue1.empty();) {
            queue1.pop();
        }
    }
}