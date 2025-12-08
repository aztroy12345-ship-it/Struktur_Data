#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

// Membuat node baru
Node* newNode(char data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Traversal Preorder
void preorder(Node* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Traversal Inorder
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// Traversal Postorder
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    /*
        Struktur pohon yang menghasilkan:
        Preorder  : R A S I T E
        Inorder   : I S T A R E
        Postorder : I T S A E R

                R
               / \
              A   E
             / \
            S   T
           /
          I
    */

    Node* root = newNode('R');
    root->left = newNode('A');
    root->right = newNode('E');
    root->left->left = newNode('S');
    root->left->right = newNode('T');
    root->left->left->left = newNode('I');

    printf("Tampilan secara PreOrder  : ");
    preorder(root);
    printf("\n");

    printf("Tampilan secara InOrder   : ");
    inorder(root);
    printf("\n");

    printf("Tampilan secara PostOrder : ");
    postorder(root);
    printf("\n");

    return 0;
}

