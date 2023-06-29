#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[8] = {0};

void func(string currnt, int num, int count) {
    if (count == 0) {
        cout << currnt << "\n";
        return;
    }
    for (int i = num; i < N; i++) {
        func(currnt + to_string(arr[i]) + " ", i, count - 1);
    }
}

// 15666번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int index, x;
    cin >> N >> M;
    index = 0;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (i == 0) {
            arr[index++] = x;
        }
        for (int j = 0; j < index; j++) {
            if (x == arr[j]) {
                break;
            }
            if (j == index - 1) {
                arr[index++] = x;
            }
        }
    }
    N = index;
    sort(arr, arr + N);
    func("", 0, M);
}
