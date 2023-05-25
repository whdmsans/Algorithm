#include <bits/stdc++.h>

using namespace std;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, x;
    stack<pair<int, int>> s1;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> x;
        for (; !s1.empty() && s1.top().first < x;) {
            s1.pop();
        }
        if (s1.empty()) {
            cout << "0 ";
        } else {
            cout << s1.top().second << " ";
        }
        s1.push(make_pair(x, i));
    }
}