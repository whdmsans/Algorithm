#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    struct tm* t;
    time_t timer;
    timer = time(NULL);
    t = localtime(&timer);

    cout << t->tm_year + 1900 << "-";
    if (t->tm_mon + 1 < 10) {
        cout << "0";
    }
    cout << t->tm_mon + 1 << "-";
    if (t->tm_mday < 10) {
        cout << "0";
    }
    cout << t->tm_mday;
}