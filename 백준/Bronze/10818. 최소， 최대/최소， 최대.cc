#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, Max, Min, a;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (i == 0) {
            Max = a;
            Min = a;
        }
        if (Max < a) {
            Max = a;
        }
        else if (Min > a) {
            Min = a;
        }
    }
    cout << Min << " " << Max;
}