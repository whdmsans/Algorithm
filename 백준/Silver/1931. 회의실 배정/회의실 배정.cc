#include <bits/stdc++.h>

using namespace std;

// 1931번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, a, b, time, cnt;
    cin >> N;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());
    cnt = 1;
    time = v[0].first;
    for (int i = 1; i < N; i++) {
        if (v[i].second >= time) {
            time = v[i].first;
            cnt++;
        }
    }
    cout << cnt;
}
