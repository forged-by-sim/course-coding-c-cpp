#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into binary search tree
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Inorder traversal (left, root, right)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Free memory
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function
int main() {
    FILE* file = fopen("tree_data.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    int* data = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        fscanf(file, "%d", &data[i]);

    fclose(file);

    // Build BST
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    printf("Inorder Traversal (Sorted Values):\n");
    inorder(root);
    printf("\n");

    free(data);
    freeTree(root);
    return 0;
}
