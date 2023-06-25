#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[8];

void func(string currnt, int num, int count) {
    if (count == 0) {
        cout << currnt << "\n";
        return;
    }
    for (int i = num; i < N; i++) {
        func(currnt + to_string(arr[i]) + " ", i, count - 1);

    }
}

// 15657번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    func("", 0, M);
}
