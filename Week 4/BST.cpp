#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = right = nullptr;
    }
};

// Thêm node vào BST
Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Inorder: Left -> Root -> Right
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Preorder: Root -> Left -> Right
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}


