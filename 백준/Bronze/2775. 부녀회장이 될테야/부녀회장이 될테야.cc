#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int pn(int a, int b) {
    if (a == 0) {
        return b;
    }
    else {
        int sum = 0;
        for (; b > 0;) {
            sum += pn(a - 1, b--);
        }
        return sum;
    }
}

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, a, b, i;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> a >> b;
        cout << pn(a, b) << "\n";
    }
}