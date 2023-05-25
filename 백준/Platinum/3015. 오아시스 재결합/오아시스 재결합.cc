#include <bits/stdc++.h>

using namespace std;

// 3015번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, h;
    cin >> n;
    stack<pair<int, int>> s1;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> h;
        for (; !s1.empty() && h > s1.top().first;) {
            cnt += s1.top().second;
            s1.pop();
        }
        if (!s1.empty() && s1.top().first == h) {
            cnt += s1.top().second++;
            if (s1.size() > 1) {
                cnt++;
            }
            continue;
        } else if (!s1.empty()) {
            cnt++;
        }
        s1.push(make_pair(h, 1));
    }
    cout << cnt;
}