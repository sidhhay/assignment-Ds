#include <iostream>
#include <queue>
using namespace std;

//one queue
class Stack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top: " << q.front() << endl;
    }

    bool empty() {
        return q.empty();
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
