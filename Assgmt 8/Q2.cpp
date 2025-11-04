#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BST {
    Node* root;

    Node* insert(Node* root, int val) {
        if (root == NULL)
            return new Node(val);

        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);

        return root;
    }

    Node* searchRecursive(Node* root, int key) {
        if (root == NULL || root->data == key)
            return root;

        if (key < root->data)
            return searchRecursive(root->left, key);
        else
            return searchRecursive(root->right, key);
    }

    //minimum node
    Node* findMin(Node* root) {
        while (root && root->left != NULL)
            root = root->left;
        return root;
    }

    //maximum node
    Node* findMax(Node* root) {
        while (root && root->right != NULL)
            root = root->right;
        return root;
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    // Recursive Search
    void searchRecursive(int key) {
        Node* res = searchRecursive(root, key);
        if (res)
            cout << key << " found (Recursive Search)\n";
        else
            cout << key << " not found (Recursive Search)\n";
    }

    // Non-Recursive Search
    void searchNonRecursive(int key) {
        Node* temp = root;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << key << " found (Non-Recursive Search)\n";
                return;
            } else if (key < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        cout << key << " not found (Non-Recursive Search)\n";
    }

    // Minimum Element
    void minimum() {
        Node* minNode = findMin(root);
        if (minNode)
            cout << "Minimum element: " << minNode->data << endl;
    }

    // Maximum Element
    void maximum() {
        Node* maxNode = findMax(root);
        if (maxNode)
            cout << "Maximum element: " << maxNode->data << endl;
    }

    // Inorder Traversal
    void inorder(Node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    // Inorder Successor
    void inorderSuccessor(int key) {
        Node* current = searchRecursive(root, key);
        if (current == NULL) {
            cout << "Node not found\n";
            return;
        }

        // Case 1: Right subtree exists
        if (current->right != NULL) {
            Node* succ = findMin(current->right);
            cout << "Inorder Successor of " << key << " is " << succ->data << endl;
            return;
        }

        // Case 2: No right subtree
        Node* successor = NULL;
        Node* ancestor = root;
        while (ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else
                ancestor = ancestor->right;
        }
        if (successor)
            cout << "Inorder Successor of " << key << " is " << successor->data << endl;
        else
            cout << "No Inorder Successor exists for " << key << endl;
    }

    // Inorder Predecessor
    void inorderPredecessor(int key) {
        Node* current = searchRecursive(root, key);
        if (current == NULL) {
            cout << "Node not found\n";
            return;
        }

        // Case 1: Left subtree exists
        if (current->left != NULL) {
            Node* pred = findMax(current->left);
            cout << "Inorder Predecessor of " << key << " is " << pred->data << endl;
            return;
        }

        // Case 2: No left subtree
        Node* predecessor = NULL;
        Node* ancestor = root;
        while (ancestor != current) {
            if (current->data > ancestor->data) {
                predecessor = ancestor;
                ancestor = ancestor->right;
            } else
                ancestor = ancestor->left;
        }
        if (predecessor)
            cout << "Inorder Predecessor of " << key << " is " << predecessor->data << endl;
        else
            cout << "No Inorder Predecessor exists for " << key << endl;
    }
};

int main() {
    BST tree;

    
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.displayInorder();

    
    tree.searchRecursive(40);
    tree.searchNonRecursive(100);

    tree.minimum();
    tree.maximum();

    tree.inorderSuccessor(50);
    tree.inorderPredecessor(50);

    return 0;
}
