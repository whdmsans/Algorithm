#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, c;
    c = 0;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        c += (a * a);
    }
    cout << c % 10;
}