#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    long long M, N;
    cin >> N >> M;
    if (N > M) {
        cout << N - M;
    }
    else {
        cout << M - N;
    }
}