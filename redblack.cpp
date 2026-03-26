#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right;

    Node(int val) {
        data = val;
        color = RED;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        Node* n = new Node(val);
        n->color = BLACK;  // root is black
        return n;
    }

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << "(" << (root->color == RED ? "R" : "B") << ") ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);

    cout << "Red-Black Tree (simple): ";
    inorder(root);

    return 0;
}