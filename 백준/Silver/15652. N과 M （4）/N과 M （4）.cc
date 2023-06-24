#include <bits/stdc++.h>

using namespace std;

int N, M;

void func(string currnt, int num, int count) {
    if (count == 0) {
        cout << currnt << "\n";
        return;
    }

    for (int i = num; i <= N; i++) {
        func(currnt + to_string(i) + " ", i, count - 1);
    }
}

// 15652번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    func("", 1, M);
}
