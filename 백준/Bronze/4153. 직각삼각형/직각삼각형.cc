#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    for (;;) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b) {
            cout << "right" << "\n";
        }
        else {
            cout << "wrong" << "\n";
        }
    }
}