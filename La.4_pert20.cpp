#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* buatNode(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->left = baru->right = NULL;
    return baru;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node *root = buatNode(10);
    root->left = buatNode(5);
    root->right = buatNode(15);

    cout << "Inorder   : "; inorder(root);
    cout << "\nPreorder  : "; preorder(root);
    cout << "\nPostorder : "; postorder(root);

    return 0;
}

