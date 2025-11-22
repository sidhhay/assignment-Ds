#include <bits/stdc++.h>
using namespace std;

/* ===================== DOUBLY LINKED LIST ===================== */

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) : data(val), next(NULL), prev(NULL) {}
};

class DoublyList {
public:
    DNode* head = NULL;

    void insertFirst(int val) {
        DNode* n = new DNode(val);
        if(!head) head = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void insertLast(int val) {
        DNode* n = new DNode(val);
        if(!head) head = n;
        else {
            DNode* temp = head;
            while(temp->next) temp = temp->next;
            temp->next = n;
            n->prev = temp;
        }
    }

    void insertAfter(int key, int val) {
        DNode* temp = head;
        while(temp && temp->data != key) temp = temp->next;
        if(!temp) return;
        DNode* n = new DNode(val);
        n->next = temp->next;
        n->prev = temp;
        if(temp->next) temp->next->prev = n;
        temp->next = n;
    }

    void insertBefore(int key, int val) {
        if(!head) return;
        if(head->data == key) return insertFirst(val);
        DNode* temp = head;
        while(temp && temp->data != key) temp = temp->next;
        if(!temp) return;
        DNode* n = new DNode(val);
        n->prev = temp->prev;
        n->next = temp;
        temp->prev->next = n;
        temp->prev = n;
    }

    void deleteNode(int key) {
        if(!head) return;
        if(head->data == key) {
            DNode* temp = head;
            head = head->next;
            if(head) head->prev = NULL;
            delete temp;
            return;
        }
        DNode* temp = head;
        while(temp && temp->data != key) temp = temp->next;
        if(!temp) return;
        if(temp->prev) temp->prev->next = temp->next;
        if(temp->next) temp->next->prev = temp->prev;
        delete temp;
    }

    bool search(int key) {
        DNode* temp = head;
        while(temp) {
            if(temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        DNode* temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


/* ===================== CIRCULAR LINKED LIST ===================== */

struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(NULL) {}
};

class CircularList {
public:
    CNode* head = NULL;

    void insertFirst(int val) {
        CNode* n = new CNode(val);
        if(!head) {
            head = n;
            n->next = head;
            return;
        }
        CNode* temp = head;
        while(temp->next != head) temp = temp->next;
        n->next = head;
        temp->next = n;
        head = n;
    }

    void insertLast(int val) {
        CNode* n = new CNode(val);
        if(!head) {
            head = n;
            n->next = head;
            return;
        }
        CNode* temp = head;
        while(temp->next != head) temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    void insertAfter(int key, int val) {
        if(!head) return;
        CNode* temp = head;
        do {
            if(temp->data == key) {
                CNode* n = new CNode(val);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while(temp != head);
    }

    void deleteNode(int key) {
        if(!head) return;
        CNode *curr = head, *prev = NULL;

        if(head->data == key) {
            CNode* last = head;
            while(last->next != head) last = last->next;
            last->next = head->next;
            head = head->next;
            return;
        }

        do {
            prev = curr;
            curr = curr->next;
        } while(curr != head && curr->data != key);

        if(curr->data == key) prev->next = curr->next;
    }

    bool search(int key) {
        if(!head) return false;
        CNode* temp = head;
        do {
            if(temp->data == key) return true;
            temp = temp->next;
        } while(temp != head);
        return false;
    }

    void display() {
        if(!head) return;
        CNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);
        cout << endl;
    }
};


/* ===================== MAIN MENU ===================== */

int main() {
    DoublyList dl;
    CircularList cl;
    int choice, val, key;

    while(true) {
        cout << "\n--- MENU (Q1) ---\n";
        cout << "1. Insert First (Doubly)\n";
        cout << "2. Insert Last (Doubly)\n";
        cout << "3. Insert After (Doubly)\n";
        cout << "4. Insert Before (Doubly)\n";
        cout << "5. Delete (Doubly)\n";
        cout << "6. Search Doubly\n";
        cout << "7. Display Doubly\n\n";

        cout << "8. Insert First (Circular)\n";
        cout << "9. Insert Last (Circular)\n";
        cout << "10. Insert After (Circular)\n";
        cout << "11. Delete (Circular)\n";
        cout << "12. Search Circular\n";
        cout << "13. Display Circular\n";

        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 0) break;

        switch(choice) {
            case 1: cin >> val; dl.insertFirst(val); break;
            case 2: cin >> val; dl.insertLast(val); break;
            case 3: cin >> key >> val; dl.insertAfter(key,val); break;
            case 4: cin >> key >> val; dl.insertBefore(key,val); break;
            case 5: cin >> key; dl.deleteNode(key); break;
            case 6: cin >> key; cout << (dl.search(key)?"Found\n":"Not found\n"); break;
            case 7: dl.display(); break;

            case 8: cin >> val; cl.insertFirst(val); break;
            case 9: cin >> val; cl.insertLast(val); break;
            case 10: cin >> key >> val; cl.insertAfter(key,val); break;
            case 11: cin >> key; cl.deleteNode(key); break;
            case 12: cin >> key; cout << (cl.search(key)?"Found\n":"Not found\n"); break;
            case 13: cl.display(); break;
        }
    }
}
