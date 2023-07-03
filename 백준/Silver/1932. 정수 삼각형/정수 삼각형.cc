#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr[501];


// 1932번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int x;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            cin >> x;
            arr[i].push_back(x);
        }
    }
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            arr[i][j] = arr[i][j] + max(arr[i + 1][j], arr[i + 1][j + 1]);
        }
    }
    cout << arr[1][0];
}
