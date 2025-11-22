#include <iostream>
#include <climits>
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

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    Node* insert(Node* root, int value) {
        if (root == NULL)
            return new Node(value);

        if (value < root->data)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);

        return root;
    }

    bool isBST(Node* root, long long minVal, long long maxVal) {
        if (root == NULL)
            return true;

        if (root->data <= minVal || root->data >= maxVal)
            return false;

        return isBST(root->left, minVal, root->data) &&
               isBST(root->right, root->data, maxVal);
    }

    void checkBST() {
        if (isBST(root, LLONG_MIN, LLONG_MAX))
            cout << "The given tree is a Binary Search Tree (BST)." << endl;
        else
            cout << "The given tree is NOT a Binary Search Tree." << endl;
    }

    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    BinaryTree tree;

    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    tree.checkBST();

    tree.root->left->right->data = 100;
    tree.checkBST();

    return 0;
}
