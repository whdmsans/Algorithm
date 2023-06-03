#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    int N = 0;
    int R = 1;
    cin >> N;
    if (N == 0) {
        R = 1;
    }
    else {
        for (int i = 1; i <= N; i++) {
            R *= i;
        }
    }
    cout << R;
}