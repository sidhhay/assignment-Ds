//Q1
#include <iostream>
using namespace std;

const int Max = 100;
int arr[Max];

void create() {
    int size = 0;
    cout << "Enter number of elements: ";
    cin >> size;

    if (size > Max) {
        cout << "Size exceeds maximum allowed!\n";
        size = 0;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Array created successfully.\n";
}



void display() {
    int size;
    if(size == 0) {
        cout << "Array is empty.\n";
        return;
    }
    else {

        cout << "Array elements: ";
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}


void insert() {
    int size = 0;
    cout << "Enter number of elements: ";
    cin >> size;
    if(size == Max) {
        cout << "Array is full. Cannot insert.\n";
        return;
    }
    int pos, value;
    cout << "Enter position to insert (0 to " << size << "): ";
    cin >> pos;
    if(pos < 0 || pos > size) {
        cout << "Invalid position!\n";
        return;
    }
    cout << "Enter value to insert: ";
    cin >> value;
    for(int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
    cout << "Element inserted successfully.\n";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void DELETE() {
    cout << "Enter number of elements: ";
    int size;
    cin >> size;
    if(size == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int pos;
    cout << "Enter position to delete (0 to " << size - 1 << "): ";
    cin >> pos;
    if(pos < 0 || pos >= size) {
        cout << "Invalid position!\n";
        return;
    }
    int deleted = arr[pos];
    for(int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Deleted element: " << deleted << endl;
    cout << "New Array:\n";
    for (int i = 0; i < size-1; i++){
         cout << arr[i] << " ";
     }
     cout << endl;
}

void linear_search() {
    int size;
    if(size == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int value;
    cout << "Enter value to search: ";
    cin >> value;
    for(int i = 0; i < size; i++) {
        if(arr[i] == value) {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found.\n";
}

int main() {
    int choice;

    do {
        cout << "MENU\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: DELETE(); break;
            case 5: linear_search(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 6);

    return 0;
}