#include<iostream>
using namespace std;

#define MAX 5
class Stack {
    int arr[MAX];
    int top;

    public:
    Stack() {
        top = -1;
    }

    //isEmpty
    bool isEmpty(){
        return (top == -1);
    }

    //isFull
    bool isFull(){
        return (top == MAX-1);
    }

    //Push
    void push(int x){
        if(isFull()) {
            cout<<"Stack Overflow!" << x << endl;
        } else {
            top = top + 1;
            arr[top] = x;
            //arr[++top] = x;
            cout<< x << " Pushed into stack\n";
        }
    }

    //Pop
    void pop(){
        if(isEmpty()) {
            cout << "Stack underflow! Cannot pop\n";
        } else {
            int x = arr[top];
            top = top - 1;
            cout<< x<< " Popped from stack\n";

            //cout<< arr[top--]<< " Popped from stack\n";
        }
    }

    //Peek
    void peek(){
        if(isEmpty()) {
            cout<<"Stack is Empty\n";
        } else {
            cout<<"Top element is: "<< arr[top]<< endl;
        }
    }

    //Display
    void display(){
        if (isEmpty()) {
            cout<<"Stack is Empty\n";
        } else {
            cout<< "Stack elements are: ";
            for(int i = top; i>=0; i--){
                cout << arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
       cout << "\n Stack Menu \n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            if (s.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";
            break;
        case 6:
            if (s.isFull())
                cout << "Stack is full.\n";
            else
                cout << "Stack is not full.\n";
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}