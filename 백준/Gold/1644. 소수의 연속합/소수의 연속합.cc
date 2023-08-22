#include <bits/stdc++.h>

using namespace std;

// 1644번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, result, sum;
    result = 0;
    cin >> N;
    vector<int> primeNum;
    vector<int> arr(N + 1);
    for (int i = 0; i <= N; i++) {
        arr[i] = 0;
    }
    for (int i = 2; i <= N; i++) {
        if (arr[i] == 1) {
            continue;
        }
        primeNum.push_back(i);
        for (int j = 1; j * i <= N; j++) {
            arr[i * j] = 1;
        }
    }
    for (int i = 0; i < primeNum.size(); i++) {
        sum = 0;
        for (int j = i; j < primeNum.size() && sum < N; j++) {
            sum += primeNum[j];
        }
        if (sum == N) {
            result++;
        }
    }
    cout << result;
    return 0;
}