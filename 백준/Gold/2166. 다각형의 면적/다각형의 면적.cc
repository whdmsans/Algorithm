#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> point[10000];

double CCW(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3) {
    double res;
    res = (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
    return res / 2;
}

// 13172번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int x, y;
    double result = 0;
    cin >> N;
    cin >> x >> y;
    point[0] = make_pair(x, y);
    cin >> x >> y;
    point[1] = make_pair(x, y);
    for (int i = 2; i < N; i++) {
        cin >> x >> y;
        point[i] = make_pair(x, y);
        result += CCW(point[0], point[i - 1], point[i]);
    }
    result = abs(result);
    cout << fixed;
    cout.precision(1);
    cout << result;

    return 0;
}