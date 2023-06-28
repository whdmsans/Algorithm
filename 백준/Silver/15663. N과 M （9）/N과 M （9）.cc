#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[8];
int visited[8] = {0};

void func(string currnt, int count) {
    if (count == 0) {
        cout << currnt << "\n";
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i] != 0) {
            continue;
        }
        visited[i] = 1;
        func(currnt + to_string(arr[i]) + " ", count - 1);
        visited[i] = 0;
        while (arr[i] == arr[i + 1]) {
            i++;
            if (i == N - 1) {
                break;
            }
        }
    }
}

// 15663번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    func("", M);
}
