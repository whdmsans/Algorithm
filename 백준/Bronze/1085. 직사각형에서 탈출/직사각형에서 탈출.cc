#include <iostream>

using namespace std;

int main() {
    int x, y, w, h, distance;
    int count = 0;
    cin >> x >> y >> w >> h;
    // x, y, w - x, h - y
    if (x >= y) { distance = y; }
    else { distance = x; }
    if (distance > w - x) {
        distance = w - x;
    }
    if (distance > h - y) {
        distance = h - y;
    }
    cout << distance;
}