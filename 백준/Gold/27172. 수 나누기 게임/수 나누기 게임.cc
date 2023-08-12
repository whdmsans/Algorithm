#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100000];
int num[1000001] = {0};
int score[1000001] = {0};

// 27172번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int maxNum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        maxNum = max(maxNum, arr[i]);
        num[arr[i]] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = arr[i] * 2; j <= maxNum; j += arr[i]) {
            if (num[j] == 1) {
                score[j]--;
                score[arr[i]]++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << score[arr[i]] << " ";
    }
    return 0;
}