#include <stdio.h>
#include <stdlib.h>

// Node structure for AVL tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to get the height of the tree
int getHeight(Node* node) {
    return (node == NULL) ? 0 : node->height;
}

// Function to get the balance factor of a node
int getBalance(Node* node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Function to perform a right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

// Function to perform a left rotation
Node* leftRotate(Node* x) {
