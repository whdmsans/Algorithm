#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

// 13172번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int M, n;
    cin >> M;
    long long b, a, num, result;
    result = 0;
    while (M-- > 0) {
        cin >> b >> a;
        num = gcd(b, a);
        b /= num;
        a /= num;
        n = mod - 2;
        num = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                num = num * b % mod;
            }
            b = b * b % mod;
            n /= 2;
        }
        num %= mod;
        result += a * num % mod;
        result %= mod;
    }
    cout << result;
    return 0;
}