#include <bits/stdc++.h>

using namespace std;

// 2493번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, h;
    stack<pair<int, int>> s1;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> h;
        for (; !s1.empty() && h >= s1.top().first;) {
            sum += i - s1.top().second - 1;
            s1.pop();
        }
        s1.push(make_pair(h, i));
    }
    for (; !s1.empty();) {
        sum += n - s1.top().second - 1;
        s1.pop();
    }
    cout << sum;
}