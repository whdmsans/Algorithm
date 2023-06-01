#include <bits/stdc++.h>

using namespace std;

// 10866번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int arr[10000 * 2];
    int head = 10000 - 1, tail = 10000;
    int N;
    string s;
    cin >> N;
    cin.ignore();
    while (N--) {
        getline(cin, s);
        if (s.find("push_front") == 0) {
            arr[head--] = stoi(s.substr(10, s.length()));
        } else if (s.find("push_back") == 0) {
            arr[tail++] = stoi(s.substr(9, s.length()));
        } else if (s.find("pop_front") == 0) {
            if (tail - head == 1) {
                cout << "-1\n";
            } else {
                cout << arr[++head] << "\n";
            }
        } else if (s.find("pop_back") == 0) {
            if (tail - head == 1) {
                cout << "-1\n";
            } else {
                cout << arr[--tail] << "\n";
            }
        } else if (s.find("size") == 0) {
            cout << tail - head - 1 << "\n";
        } else if (s.find("empty") == 0) {
            if (tail - head == 1) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if (s.find("front") == 0) {
            if (tail - head == 1) {
                cout << "-1\n";
            } else {
                cout << arr[head + 1] << "\n";
            }
        } else if (s.find("back") == 0) {
            if (tail - head == 1) {
                cout << "-1\n";
            } else {
                cout << arr[tail - 1] << "\n";
            }
        }
    }
}
