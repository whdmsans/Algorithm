#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N, V;
    cin >> N;
    int* a = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    cin >> V;
    for (int i = 0; i < N; i++) {
        if (V == a[i]) {
            cnt++;
        }
    }
    cout << cnt;

    delete[] a;
}