#include <bits/stdc++.h>

using namespace std;

int N;
int A[1000];
int increase_dp[1000];
int decrease_dp[1000];

// 11054번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int result = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        increase_dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                increase_dp[i] = max(increase_dp[i], increase_dp[j] + 1);
            }
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        decrease_dp[i] = 1;
        for (int j = N - 1; j > i; j--) {
            if (A[i] > A[j]) {
                decrease_dp[i] = max(decrease_dp[i], decrease_dp[j] + 1);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        result = max(result, increase_dp[i] + decrease_dp[i]);
    }
    cout << result - 1;
}