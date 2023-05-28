#include <bits/stdc++.h>

using namespace std;

// 18870번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, cnt;
    cin >> N;
    vector<pair<int, int>> v1;
    int a[N];
    cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        v1.push_back(make_pair(a[i], i));
    }
    sort(v1.begin(), v1.end());
    for (int i = 0; i < N; i++) {
        a[v1[i].second] = cnt++;
        if (i != N - 1 && v1[i + 1].first == v1[i].first) {
            cnt--;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
}