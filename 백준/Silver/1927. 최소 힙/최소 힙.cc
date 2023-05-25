#include <bits/stdc++.h>

using namespace std;

// 1927번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, x;
    priority_queue<int, vector<int>, greater<int>> pq1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (pq1.empty()) {
                cout << "0\n";
            } else {
                cout << pq1.top() << "\n";
                pq1.pop();
            }
        } else {
            pq1.push(x);
        }
    }
}