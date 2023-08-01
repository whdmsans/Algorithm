#include <bits/stdc++.h>

using namespace std;

// 18110번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, num;
    double result;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    num = (int) round(n * 0.15);
    result = 0;
    for (int i = num; i < n - num; i++) {
        result += arr[i];
    }
    result = round(result / (n - 2 * num));
    cout << result;

    delete[] arr;
    return 0;
}