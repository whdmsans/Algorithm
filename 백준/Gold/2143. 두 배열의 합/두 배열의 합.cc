#include <bits/stdc++.h>

using namespace std;

int T, n, m, sum, sizeA, sizeB;
long long answer = 0;
int A[1000];
int B[1000];
int arrA[999000];
int arrB[999000];

// 2143번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;
    cin >> n;
    sizeA = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum = 0;
        for (int j = i; j >= 0; j--) {
            sum += A[j];
            arrA[sizeA++] = sum;
        }
    }
    cin >> m;
    sizeB = 0;
    for (int i = 0; i < m; i++) {
        cin >> B[i];
        sum = 0;
        for (int j = i; j >= 0; j--) {
            sum += B[j];
            arrB[sizeB++] = sum;
        }
    }
    sort(arrB, arrB + sizeB);
    for (int i = 0; i < sizeA; i++) {
        answer +=
                (upper_bound(arrB, arrB + sizeB, T - arrA[i]) - arrB) -
                (lower_bound(arrB, arrB + sizeB, T - arrA[i]) - arrB);
    }
    cout << answer;
    return 0;
}