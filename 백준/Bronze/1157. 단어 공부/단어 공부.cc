#include <iostream>
#include <string>
using namespace std;

int main() {
    string Text;
    int size[26] = { 0, };
    cin >> Text;
    for (int i = 0; i < Text.length(); i++) {
        if (Text[i] >= 'a') {
            size[Text[i] - 'a']++;
        }
        else {
            size[Text[i] - 'A']++;
        }
    }
    int max = -1;
    char a;
    for (int i = 0; i < 26; i++) {
        if (max < size[i]) {
            max = size[i];
            a = 'A' + i;
        }
        else if (max == size[i]) {
            a = '?';
        }
    }
    cout << a;
}