#include<iostream>
#include<stack>
using namespace std;

int main() {
    string str = "DataStructure";
    stack<char> s;

    // Push each character onto the stack
    for (char c : str) {
        s.push(c);
    }

    // Pop characters from stack to reverse
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reversed << endl;

    return 0;
}