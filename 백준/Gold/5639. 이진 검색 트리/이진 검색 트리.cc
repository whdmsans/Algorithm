#include <bits/stdc++.h>

using namespace std;

int arr[10000];

void func(int s, int e) {
    if (s > e) {
        return;
    }
    if (s == e) {
        cout << arr[s] << "\n";
        return;
    }
    int p = s + 1;
    while (p <= e && arr[s] > arr[p]) {
        p++;
    }
    if (p > s + 1) {
        func(s + 1, p - 1);
    }
    if (p <= e) {
        func(p, e);
    }
    cout << arr[s] << "\n";
}

// 5639번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, N;
    N = 0;

    while (cin >> n) {
        arr[N++] = n;
    }
    func(0, N - 1);
}
