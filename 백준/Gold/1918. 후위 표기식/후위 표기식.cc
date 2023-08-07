#include <bits/stdc++.h>

using namespace std;

// 1918번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string exp;
    char temp;
    stack<char> stack1;
    cin >> exp;
    for (int i = 0; i < exp.length(); i++) {
        temp = exp[i];
        if (temp >= 'A' && temp <= 'Z') {
            cout << temp;
            continue;
        }
        if (stack1.empty()) {
            stack1.push(temp);
            continue;
        }
        switch (temp) {
            case '(':
                stack1.push(temp);
                break;
            case ')':
                temp = stack1.top();
                stack1.pop();
                while (temp != '(') {
                    cout << temp;
                    temp = stack1.top();
                    stack1.pop();
                }
                break;
            case '*':
            case '/':
                if (stack1.top() == '*' || stack1.top() == '/') {
                    cout << stack1.top();
                    stack1.pop();
                }
                stack1.push(temp);
                break;
            case '+':
            case '-':
                if (stack1.top() == '*' || stack1.top() == '/') {
                    cout << stack1.top();
                    stack1.pop();
                }
                if (!stack1.empty() && stack1.top() != '(') {
                    cout << stack1.top();
                    stack1.pop();
                }
                stack1.push(temp);
                break;
        }
    }
    while (!stack1.empty()) {
        cout << stack1.top();
        stack1.pop();
    }
    return 0;
}