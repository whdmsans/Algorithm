#include <iostream>
using namespace std;

int main() {
    int N, F, i;

    cin >> N;
    cin >> F;
    N = N / 100 * 100;
    for (i = 0; (N + i) % F != 0; i++);
    if (i < 10) { cout << "0"; }
    cout << i;
}