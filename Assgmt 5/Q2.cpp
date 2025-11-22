#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int countAndDeleteOccurrences(int key) {
    int count = 0;

    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            count++;
        } else {
            current = current->next;
        }
    }
    return count;
}

int main() {

    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtEnd(3);
    insertAtEnd(1);

    cout << "Original ";
    displayList();

    int key;
    cout << "Enter key to count & delete: ";
    cin >> key;

    int occurrences = countAndDeleteOccurrences(key);
    cout << "Occurrences of " << key << " = " << occurrences << endl;

    cout << "After deletion ";
    displayList();

    return 0;
}