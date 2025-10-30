#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int key;
    string val;
    Node* left, * right;
};

struct BST {
    Node* root = nullptr;

    Node* newNode(int k, string v) {
        Node* p = new Node;
        p->key = k; p->val = v;
        p->left = p->right = nullptr;
        return p;
    }

    
    Node* put(Node* r, int k, string v) {
        if (!r) return newNode(k, v);
        if (k < r->key) r->left = put(r->left, k, v);
        else if (k > r->key) r->right = put(r->right, k, v);
        else r->val = v;
        return r;
    }
    void put(int k, string v) { root = put(root, k, v); }

    


    Node* get(Node* r, int k) {
        if (!r) return nullptr;
        if (k < r->key) return get(r->left, k);
        if (k > r->key) return get(r->right, k);
        return r;
    }
    string get(int k) {
        Node* p = get(root, k);
        return p ? p->val : "Not found";
    }

   


    Node* minNode(Node* r) {
        while (r && r->left) r = r->left;
        return r;
    }

    Node* del(Node* r, int k) {
        if (!r) return nullptr;
        if (k < r->key) r->left = del(r->left, k);
        else if (k > r->key) r->right = del(r->right, k);
        else {
            if (!r->left) return r->right;
            if (!r->right) return r->left;
            Node* t = minNode(r->right);
            r->key = t->key;
            r->val = t->val;
            r->right = del(r->right, t->key);
        }
        return r;
    }
    void del(int k) { root = del(root, k); }

    


    void inorder(Node* r) {
        if (!r) return;
        inorder(r->left);
        cout << r->key << " ";
        inorder(r->right);
    }
    void print() {
        cout << "BST: ";
        inorder(root);
        cout << endl;
    }

  


    bool isBST(Node* r, int minV, int maxV) {
        if (!r) return true;
        if (r->key <= minV || r->key >= maxV) return false;
        return isBST(r->left, minV, r->key) && isBST(r->right, r->key, maxV);
    }
    bool isBST() { return isBST(root, -1e9, 1e9); }





    int height(Node* r) {
        if (!r) return 0;
        int l = height(r->left), rr = height(r->right);
        if (abs(l - rr) > 1) throw 0;
        return max(l, rr) + 1;
    }
    bool isBalancedBST() {
        try { height(root); return true; }
        catch (...) { return false; }
    }

    bool isBinaryTree() { return true; }
};
