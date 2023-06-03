#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int h, w, n, t, fn, rn;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> h >> w >> n;
        fn = n % h;
        rn = 1 + n / h;
        if (fn == 0) {
            fn = h;
            rn--;
        }
        n = fn * 100 + rn;
        cout << n << "\n";
    }
}