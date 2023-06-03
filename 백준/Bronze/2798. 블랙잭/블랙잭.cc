#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    int a[100] = { 0, };
    int sum = 0;
    int min;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    min = 300000;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                sum = a[i] + a[j] + a[k];
                if (sum <= m && min > m - sum) {
                    min = m - sum;
                }
            }
        }
    }
    cout << m - min;
}