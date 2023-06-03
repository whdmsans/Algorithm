#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int H, M;
    cin >> H >> M;
    if (M < 45) {
        M = M + 60;
        if (H == 0) {
            H = 23;
        }
        else {
            H--;
        }
    }
    M = M - 45;
    cout << H << " " << M;
}