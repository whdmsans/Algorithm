#include <bits/stdc++.h>

using namespace std;

// 1158번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k, i;
    cin >> n >> k;
    queue<int> q1, q2;
    for (i = 1; i <= n; i++) {
        q1.push(i);
    }
    for (; !q1.empty();) {
        for (i = 0; i < k - 1; i++) {
            q1.push(q1.front());
            q1.pop();
        }
        q2.push(q1.front());
        q1.pop();
    }
    for (i = 0; !q2.empty(); i++) {
        if (i == 0) {
            cout << "<";
        }
        cout << q2.front();
        q2.pop();
        if (q2.empty()) {
            cout << ">";
        } else {
            cout << ", ";
        }
    }

    return 0;
}