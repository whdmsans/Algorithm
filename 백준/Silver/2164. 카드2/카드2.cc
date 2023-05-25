#include <bits/stdc++.h>

using namespace std;

// 2164번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    queue<int> queue1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        queue1.push(i);
    }
    for (; queue1.size() != 1;) {
        queue1.pop();
        queue1.push(queue1.front());
        queue1.pop();
    }
    cout << queue1.front();
}