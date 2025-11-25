#include <iostream>
#include <queue>
using namespace std;

//two queues
class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        cout << "Popped: " << q1.front() << endl;
        q1.pop();

        swap(q1, q2);
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        cout << "Top: " << q1.front() << endl;

        q2.push(q1.front());
        q1.pop();

        swap(q1, q2);
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();   // Pops 3
    s.push(4);
    s.top();   // Shows 4
    s.pop();   // Pops 4
    return 0;
}
