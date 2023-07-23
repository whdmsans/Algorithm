#include <bits/stdc++.h>

using namespace std;

long long N, B;

long long A[5][5];
long long answer[5][5] = {{1, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0},
                          {0, 0, 1, 0, 0},
                          {0, 0, 0, 1, 0},
                          {0, 0, 0, 0, 1}};
long long tmp[5][5];

void func(long long arr1[5][5], long long arr2[5][5]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < N; k++) {
                tmp[i][j] += (arr1[i][k] * arr2[k][j]) % 1000;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr1[i][j] = tmp[i][j] % 1000;
        }
    }
}

void print(long long arr[5][5]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

// 10830번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    while (B > 1) {
        if (B % 2 == 1) {
            func(answer, A);
        }
        func(A, A);
        B /= 2;
    }
    func(answer, A);
    print(answer);
}