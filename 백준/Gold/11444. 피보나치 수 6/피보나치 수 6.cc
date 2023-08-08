#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> matrix;
const int mod = 1000000007;

long long n;
matrix A = {{1, 1},
            {1, 0}};
matrix answer = {{1, 0},
                 {0, 1}};

matrix operator*(matrix &a, matrix &b) {
    matrix c(2, vector<int>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += (long long) a[i][k] * b[k][j] % mod;
            }
            c[i][j] %= mod;
        }
    }
    return c;
}

// 11444번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    n--;
    while (n > 0) {
        if (n % 2 == 1) {
            answer = answer * A;
        }
        A = A * A;
        n /= 2;
    }
    cout << answer[0][0];
    return 0;
}