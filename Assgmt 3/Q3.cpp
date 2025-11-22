#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string str) {
    stack<char> s;

    for (char ch : str) {
        // If opening bracket, push it
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If closing bracket, check match
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;  // mismatch
            }
        }
    }

    return s.empty();
}

int main() {
    string str;
    cout << "Enter an expression: ";
    cin >> str;

    if (isBalanced(str))
        cout << "The expression has balanced parentheses.\n";
    else
        cout << "The expression does not have balanced parentheses.\n";

    return 0;
}