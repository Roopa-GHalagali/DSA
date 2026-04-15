Question 1
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find minimum value node
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal (sorted output)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n, i, val, insertVal, deleteVal;
    struct Node* root = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input and insert nodes
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Insert additional node
    scanf("%d", &insertVal);
    root = insert(root, insertVal);

    // Delete a node
    scanf("%d", &deleteVal);
    root = deleteNode(root, deleteVal);

    // Output sorted order
    printf("Current File Index sorted in ascending order: ");
    inorder(root);

    return 0;
}


Question 2
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// inorder traversal without trailing space
void inorder(struct Node* root, int *first) {
    if (root != NULL) {
        inorder(root->left, first);

        if (*first) {
            printf("%d", root->data);
            *first = 0;
        } else {
            printf(" %d", root->data);
        }

        inorder(root->right, first);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    // Check invalid n
    if (n == -1) {
        printf("Invalid input");
        return 0;
    }

    int arr[100];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == -1) {
            printf("Invalid input");
            return 0;
        }
    }

    int insertVal;
    scanf("%d", &insertVal);

    if (insertVal == -1) {
        printf("Invalid input");
        return 0;
    }

    struct Node* root = NULL;

    // Build BST
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    // Insert new router
    root = insert(root, insertVal);

    // Print inorder
    int first = 1;
    inorder(root, &first);

    printf("\n");

    return 0;
}
