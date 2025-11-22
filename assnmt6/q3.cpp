#include <bits/stdc++.h>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) : data(val), next(NULL), prev(NULL) {}
};

struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(NULL) {}
};

int sizeDoubly(DNode* head) {
    int count = 0;
    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

int sizeCircular(CNode* head) {
    if(!head) return 0;
    int count = 0;
    CNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while(temp != head);
    return count;
}

int main() {
    // Example linked lists — add data as needed
    DNode* d1 = new DNode(10);
    d1->next = new DNode(20);
    d1->next->next = new DNode(30);

    CNode* c1 = new CNode(5);
    CNode* c2 = new CNode(15);
    c1->next = c2;
    c2->next = c1;

    cout << "Size Doubly: " << sizeDoubly(d1) << endl;
    cout << "Size Circular: " << sizeCircular(c1) << endl;
}
