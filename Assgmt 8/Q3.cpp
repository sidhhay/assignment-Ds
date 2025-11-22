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
        else
            cout << "Duplicate value " << val << " not allowed!\n";
        return root;
    }

    Node* findMin(Node* root) {
        while (root && root->left != NULL)
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int val) {
        if (root == NULL) {
            cout << "Value " << val << " not found!\n";
            return root;
        }

        if (val < root->data)
            root->left = deleteNode(root->left, val);
        else if (val > root->data)
            root->right = deleteNode(root->right, val);
        else {
            // Node found
            if (root->left == NULL && root->right == NULL) {
                // No child
                delete root;
                return NULL;
            }
            else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else {
                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }

    void inorder(Node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    int maxDepth(Node* root) {
        if (root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    int minDepth(Node* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL)
            return 1 + minDepth(root->right);
        if (root->right == NULL)
            return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void deleteValue(int val) {
        root = deleteNode(root, val);
    }

    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayDepths() {
        cout << "Maximum Depth: " << maxDepth(root) << endl;
        cout << "Minimum Depth: " << minDepth(root) << endl;
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

    cout << "\nAfter deleting 20:\n";
    tree.deleteValue(20);
    tree.displayInorder();

    cout << "\nAfter deleting 30:\n";
    tree.deleteValue(30);
    tree.displayInorder();

    cout << "\nAfter deleting 50:\n";
    tree.deleteValue(50);
    tree.displayInorder();

    cout << endl;
    tree.displayDepths();

    return 0;
}
