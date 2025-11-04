#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class CircularLL{
    Node* head;

    public:
    CircularLL(){
        head = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
         if (head == NULL) {
            head = newNode;
            newNode->next = head; // make it circular
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

        void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout<< head->data << endl;
    }

};
int main() {
    CircularLL l;
    l.insert(20);
    l.insert(100);
    l.insert(40);
    l.insert(80);
    l.insert(60);

    cout<<"Elements are:"<<endl;
    l.display();
    return 0;
}