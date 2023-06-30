#include <bits/stdc++.h>

using namespace std;

long long A, B;

void bfs() {
    queue<pair<long long, long long>> q;
    q.push(make_pair(A, 1));
    while (!q.empty()) {
        if (q.front().first == B) {
            cout << q.front().second;
            return;
        }
        if (q.front().first * 2 <= B) {
            q.push(make_pair(q.front().first * 2, q.front().second + 1));
        }
        if (q.front().first * 10 + 1 <= B) {
            q.push(make_pair(q.front().first * 10 + 1, q.front().second + 1));
        }
        q.pop();
    }
    cout << "-1";
    return;
}

// 16953번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> A >> B;
    bfs();
}
