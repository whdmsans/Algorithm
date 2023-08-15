#include <bits/stdc++.h>

using namespace std;

int num[100000];
int sum[100001];

// 1806번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, S;
    cin >> N >> S;
    sum[0] = 0;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        sum[i + 1] = sum[i] + num[i];
    }
    int start, end, length;
    start = 0;
    end = 1;
    length = N + 1;
    while (start < N && end <= N) {
        if (sum[end] - sum[start] >= S) {
            length = min(length, end - start);
            if (end - start == 1) {
                break;
            } else {
                start++;
            }
        } else {
            end++;
        }
    }
    if (length < N + 1) {
        cout << length;
    } else {
        cout << "0";
    }
    return 0;
}