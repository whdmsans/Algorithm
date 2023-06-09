#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// 6064번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, M, N, x, y, max, result;
    cin >> T;
    for (; T > 0; T--) {
        result = -1;
        cin >> M >> N >> x >> y;
        max = lcm(M, N);
        for (; x <= max; x += M) {
            if (x % N == y % N) {
                result = x;
                break;
            }
        }
        cout << result << "\n";
    }
}
