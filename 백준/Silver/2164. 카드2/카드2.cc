#include <bits/stdc++.h>

using namespace std;

// 2164번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    while (q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
    return 0;
}
