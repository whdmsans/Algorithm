#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    int a, b;
    for (;;) {
        cin >> a >> b;
        if (cin.eof() == true) {
            break;
        }
        cout << a + b << "\n";
    }
}