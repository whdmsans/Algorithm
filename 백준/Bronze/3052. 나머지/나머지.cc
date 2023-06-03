#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A[42] = { 0, };
    int a;
    for (int i = 0; i < 10; i++) {
        cin >> a;
        A[a % 42]++;
    }
    a = 0;
    for (int i = 0; i < 42; i++) {
        if (A[i] != 0) {
            a++;
        }
    }
    cout << a;
}