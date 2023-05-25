#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int* a = new int[n];
    int* p = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = a[i];
    }
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == p[j]) {
                cout << j << " ";
                p[j] = 0;
                break;
            }
        }
    }
}