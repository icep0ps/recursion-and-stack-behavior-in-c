#include <stdio.h>
#include <stdlib.h>

/* Tree node definition */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create a new tree node */
struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Preorder Traversal: Root -> Left -> Right */
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

/* Inorder Traversal: Left -> Root -> Right */
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* Postorder Traversal: Left -> Right -> Root */
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

/* Recursive Tree Deletion (Postorder) */
void deleteTree(struct Node* root) {
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    printf("Deleting node: %d\n", root->data);
    free(root);
}
//calculating height in a BST
int height(struct Node* root) {
    if (root == NULL)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}


int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder Traversal : ");
    preorder(root);
    printf("\n");

    //printf("Inorder Traversal  : ");
    //inorder(root);
    //printf("\n");

    //printf("Postorder Traversal: ");
   // postorder(root);
    //printf("\n");

    //printf("\nDeleting entire tree...\n");
    //deleteTree(root->left->left);
    //printf("\nHeight of the tree: %d\n", height(root));
    root = NULL;   

    return 0;
}
