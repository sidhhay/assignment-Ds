#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

bool isCircular(Node* head) {
    if(!head) return false;
    Node* temp = head->next;
    while(temp && temp != head) temp = temp->next;
    return temp == head;
}

int main() {
    Node* head = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);

    head->next = n2;
    n2->next = n3;
    n3->next = head; // make circular

    cout << (isCircular(head) ? "Circular" : "Not Circular") << endl;
}
