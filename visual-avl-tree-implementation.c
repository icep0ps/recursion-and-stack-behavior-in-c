#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Node Structure [cite: 91-95]
typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
  int height;
} Node;

// Global buffer for vertical rendering
#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 12
char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

// Helper Functions [cite: 236-238, 262-264]
int max(int a, int b) { return (a > b) ? a : b; }
int getHeight(Node *n) { return (n == NULL) ? 0 : n->height; }

Node *newNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->left = node->right = NULL;
  node->height = 1;
  return node;
}

// 3. AVL Rotations [cite: 200-220, 224-270]
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  return x;
}

Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
  return y;
}

int getBalance(Node *n) {
  return (n == NULL) ? 0 : getHeight(n->left) - getHeight(n->right);
}

// 4. Balanced Insertion [cite: 184, 190-193, 271-274]
Node *insert(Node *node, int data) {
  if (node == NULL)
    return newNode(data);
  if (data < node->data)
    node->left = insert(node->left, data);
  else if (data > node->data)
    node->right = insert(node->right, data);
  else
    return node;

  node->height = 1 + max(getHeight(node->left), getHeight(node->right));
  int balance = getBalance(node);

  if (balance > 1 && data < node->left->data)
    return rightRotate(node);
  if (balance < -1 && data > node->right->data)
    return leftRotate(node);
  if (balance > 1 && data > node->left->data) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  if (balance < -1 && data < node->right->data) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
  return node;
}

// 5. Vertical Renderer Logic
void draw_to_buffer(Node *root, int x, int y, int gap) {
  if (root == NULL || y >= SCREEN_HEIGHT || x < 0 || x >= SCREEN_WIDTH)
    return;

  // Convert data to string and place in buffer
  char val[10];
  sprintf(val, "%d", root->data);
  int len = strlen(val);
  for (int i = 0; i < len && (x + i) < SCREEN_WIDTH; i++) {
    screen[y][x + i] = val[i];
  }

  // Draw branches and recurse [cite: 195, 203, 215]
  if (root->left) {
    screen[y + 1][x - 1] = '/';
    draw_to_buffer(root->left, x - gap, y + 2, gap / 2);
  }
  if (root->right) {
    screen[y + 1][x + len] = '\\';
    draw_to_buffer(root->right, x + gap, y + 2, gap / 2);
  }
}

void printVertical(Node *root) {
  for (int i = 0; i < SCREEN_HEIGHT; i++)
    memset(screen[i], ' ', SCREEN_WIDTH);

  draw_to_buffer(root, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 4);

  for (int i = 0; i < SCREEN_HEIGHT; i++) {
    int last = SCREEN_WIDTH - 1;
    while (last >= 0 && screen[i][last] == ' ')
      last--;
    if (last >= 0) {
      for (int j = 0; j <= last; j++)
        putchar(screen[i][j]);
      putchar('\n');
    }
  }
}

// 6. Driver Script [cite: 135]
int main() {
  Node *root = NULL;
  int values[] = {10, 20, 30,
                  40, 50, 25}; // These values trigger rotations [cite: 190-193]

  printf("--- AVL TREE VERTICAL DEMONSTRATION ---\n");

  for (int i = 0; i < 6; i++) {
    printf("\nInserting [%d]...\n", values[i]);
    root = insert(root, values[i]);
    printVertical(root);
    printf("\n---------------------------------------\n");
  }

  return 0;
}
