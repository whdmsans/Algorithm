#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100000];

// 2467번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int x, left, right, gap;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        arr[i] = x;
    }
    if (arr[0] > 0) {
        cout << arr[0] << " " << arr[1];
        return 0;
    } else if (arr[N - 1] < 0) {
        cout << arr[N - 2] << " " << arr[N - 1];
        return 0;
    }
    gap = 2000000000;
    for (int l = 0, r = N - 1; l < r;) {
        if (abs(arr[l] + arr[r]) < gap) {
            gap = abs(arr[l] + arr[r]);
            left = l;
            right = r;
            if (gap == 0) {
                break;
            }
        }
        if (abs(arr[l]) > abs(arr[r])) {
            l++;
        } else if (abs(arr[l]) < abs(arr[r])) {
            r--;
        }
    }
    cout << arr[left] << " " << arr[right];
    return 0;
}