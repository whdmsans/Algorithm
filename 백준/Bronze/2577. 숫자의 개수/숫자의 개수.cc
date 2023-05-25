#include <bits/stdc++.h>

using namespace std;

// 2577번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long a, b, c;
    int num[10] = {0,};
    cin >> a;
    cin >> b;
    cin >> c;

    a = a * b * c;
    for (; a != 0;) {
        num[a % 10]++;
        a = a / 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << num[i] << "\n";
    }
}