#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    int N = 0;
    float max = 0;
    float count = 0;
    int i;
    cin >> N;
    float* arr = new float[N];
    for (i = 0; i < N; i++) {
        cin >> arr[i];
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    for (i = 0; i < N; i++) {
        arr[i] = (arr[i] / max) * 100;
        count += arr[i];
    }
    cout << count / N;

    delete[] arr;
}