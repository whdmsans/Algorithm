#include <bits/stdc++.h>

using namespace std;

// 1874번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, flag, cnt;
    cin >> n;
    int a[n], b[n];
    stack<int> stack1;
    char c[2 * n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    flag = 0;
    cnt = 0;
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        if (stack1.empty() || stack1.top() != a[i]) {
            if (flag >= n) {
                flag = -1;
                break;
            }
            for (; a[i] != b[flag];) {
                stack1.push(b[flag++]);
                c[cnt++] = '+';
            }
            stack1.push(b[flag++]);
            c[cnt++] = '+';
        }
        stack1.pop();
        c[cnt++] = '-';
    }
    if (flag == -1) {
        cout << "NO";
    } else {
        for (int i = 0; i < 2 * n; i++) {
            cout << c[i] << "\n";
        }
    }
}