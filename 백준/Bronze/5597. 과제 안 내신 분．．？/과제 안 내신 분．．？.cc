#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int student[30] = { 0, };
    int number;
    for (int i = 0; i < 28; i++) {
        cin >> number;
        student[number -1]++;
    }
    for (int i = 0; i < 30; i++) {
        if (student[i] == 0) {
            cout << i + 1 << "\n";
        }
    }
}