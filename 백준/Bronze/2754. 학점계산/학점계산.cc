#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    char g[3];
    map<string, string> m = {
        { "A+", "4.3" }, { "A0", "4.0" }, { "A-", "3.7" },
        { "B+", "3.3" }, { "B0", "3.0" }, { "B-", "2.7" },
        { "C+", "2.3" }, { "C0", "2.0" }, { "C-", "1.7" },
        { "D+", "1.3" }, { "D0", "1.0" }, { "D-", "0.7" },
        { "F", "0.0" }
    };
    cin >> g;
    cout << m.at(g);
}