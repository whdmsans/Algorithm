#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    int y;
    cin >> y;
    if (y % 400 == 0) {
        cout << "1";
    }
    else if (y % 4 == 0 && y % 100 != 0) {
        cout << "1";
    }
    else {
        cout << "0";
    }
}