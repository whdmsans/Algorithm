#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, m1, m2, i;
    cin >> a >> b;
    if (a > b) {
        m1 = a;
        m2 = b;
    }
    else
    {
        m1 = b;
        m2 = a;
    }
    for (i = m2; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            cout << i << "\n";
            break;
        }
    }
    for (i = m1;; i++) {
        if (i % a == 0 && i % b == 0) {
            cout << i << "\n";
            break;
        }
    }
}