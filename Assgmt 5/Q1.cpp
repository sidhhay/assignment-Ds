#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeg(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    
    if(head==NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertInBetween(int val, int key, bool before) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        cout << "List is empty.\n";
        delete newNode;
        return;
    }

    if (before && head->data == key) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        if (before && temp->next != NULL && temp->next->data == key) {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        else if (!before && temp->data == key) {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
    cout << "Key " << key << " not found.\n";
    delete newNode;
}

void deleteFromBeg(){
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

void deleteSpecific(int key) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Key " << key << " not found.\n";
        return;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
}

void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node " << key << " not found.\n";
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

int main(){

    int choice, val, key;
    bool beforeAfter;

    do {
        cout << "\n Singly Linked List Menu \n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search a Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertAtBeg(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertAtEnd(val);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter key (node value before which to insert): ";
                cin >> key;
                insertInBetween(val, key, true);
                break;

            case 4:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter key (node value after which to insert): ";
                cin >> key;
                insertInBetween(val, key, false);
                break;

            case 5:
                deleteFromBeg();
                break;

            case 6:
                deleteFromEnd();
                break;

            case 7:
                cout << "Enter key (node value to delete): ";
                cin >> key;
                deleteSpecific(key);
                break;

            case 8:
                cout << "Enter key to search: ";
                cin >> key;
                searchNode(key);
                break;

            case 9:
                displayList();
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}