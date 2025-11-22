#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char c) : data(c), next(NULL), prev(NULL) {}
};

bool isPalindrome(Node* head) {
    if(!head) return true;
    Node* start = head;
    Node* end = head;
    
    while(end->next) end = end->next;
    
    while(start != end && end->next != start) {
        if(start->data != end->data) return false;
        start = start->next;
        end = end->prev;
    }
    return true;
}

int main() {
    // Example: A <-> B <-> C <-> B <-> A
    Node* head = new Node('A');
    head->next = new Node('B'); head->next->prev = head;
    head->next->next = new Node('C'); head->next->next->prev = head->next;
    head->next->next->next = new Node('B'); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node('A'); head->next->next->next->next->prev = head->next->next->next;

    cout << (isPalindrome(head) ? "Palindrome" : "Not Palindrome") << endl;
}
