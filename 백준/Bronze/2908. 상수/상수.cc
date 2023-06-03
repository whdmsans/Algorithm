#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;
    A = (A % 10) * 100 + (A % 100) - (A % 10) + A / 100;
    B = (B % 10) * 100 + (B % 100) - (B % 10) + B / 100;
    if (A > B) {
        cout << A;
    }
    else {
        cout << B;
    }
}