i i#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(int arr[], int n) {
    idx++;
    if(idx >= n || arr[idx] == -1)
        return NULL;

    Node* root = new Node(arr[idx]);
    root->left = buildTree(arr, n);
    root->right = buildTree(arr, n);
    return root;
}

void preOrder(Node* root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root)
{
    if (root == NULL)
        return; 
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    int arr[]= {10, 9, 4, -1, 8, -1, -1, -1, 17, 11, -1, -1, 21, 19, -1, -1, 25, -1, -1}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* root = buildTree(arr, n);

    cout<<"Preorder Traversal: ";
    preOrder(root);
    cout<<endl;

    cout<<"Inorder Traversal: ";
    inOrder(root);
    cout<<endl;

    cout<<"Postorder Traversal: ";
    postOrder(root);
    cout<<endl;

    return 0;
}