#include <bits/stdc++.h>

using namespace std;

// 7568번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, i, j, dn;
    int x[50] = {0,};
    int y[50] = {0,};
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (i = 0; i < n; i++) {
        dn = 1;
        for (j = 0; j < n; j++) {
            if (x[i] < x[j] && y[i] < y[j]) {
                dn++;
            }
        }
        cout << dn << " ";
    }
}