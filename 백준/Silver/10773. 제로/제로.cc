#include <bits/stdc++.h>

using namespace std;

// 10773번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int k, m;
    stack<int> s;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> m;
        if (m == 0) {
            s.pop();
        } else {
            s.push(m);
        }
    }
    m = 0;
    for (; !s.empty();) {
        m += s.top();
        s.pop();
    }
    cout << m;
}