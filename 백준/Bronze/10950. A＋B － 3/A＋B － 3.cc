#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    int N = 0;
    cin >> N;
    int* a = new int[N];
    int* b = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < N; i++) {
        cout << a[i] + b[i] << "\n";
    }

    delete[] a;
    delete[] b;
}