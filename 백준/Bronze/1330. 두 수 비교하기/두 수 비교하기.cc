#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        cout << ">";
    }
    else if (a < b) {
        cout << "<";
    }
    else {
        cout << "==";
    }
}