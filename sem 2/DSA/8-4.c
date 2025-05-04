#include <stdio.h>
#include <stdlib.h>

// Macro to get max of two numbers
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Node structure for AVL tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to get height of the tree
int getHeight(struct Node* node) {
    return (node == NULL) ? 0 : node->height;
}

// Function to get balance factor
int getBalance(struct Node* node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Function for right rotation
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = MAX(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = MAX(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Function for left rotation
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = MAX(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = MAX(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Function to insert a node into the AVL tree
struct Node* insert(struct Node* node, int value) {
    if (node == NULL)
        return createNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node; // Duplicate values not allowed

    node->height = 1 + MAX(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Balance tree using rotations
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to perform inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert nodes into AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder traversal of AVL tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
