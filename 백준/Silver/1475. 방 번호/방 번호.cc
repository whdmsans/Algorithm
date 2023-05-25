#include <bits/stdc++.h>

using namespace std;

// 1475번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    int num[10] = {0,};
    cin >> n;
    for (; n != 0;) {
        num[n % 10]++;
        n = n / 10;
    }
    num[6] = (num[6] + num[9]) / 2 + (num[6] + num[9]) % 2;
    for (int i = 0; i < 9; i++) {
        if (n < num[i]) {
            n = num[i];
        }
    }
    cout << n;
}