#include <bits/stdc++.h>

using namespace std;

int A, B, C;

long long func(int x) {
    if (x == 1) {
        return A % C;
    }
    long long N = func(x / 2) % C;
    if (x % 2 == 1) {
        return ((A % C) * ((N * N) % C)) % C;
    }
    return (N * N) % C;
}

// 1629번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> A >> B >> C;
    cout << func(B) % C;
}
