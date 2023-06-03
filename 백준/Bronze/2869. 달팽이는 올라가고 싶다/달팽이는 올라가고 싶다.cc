#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long  a, b, v, i;
    cin >> a >> b >> v;
    i = (v - a) / (a - b);
    if ((v - a) % (a - b) == 0) {
        cout << i + 1;
    }
    else {
        cout << i + 2;
    }
}