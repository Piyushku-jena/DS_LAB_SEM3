#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct node {
    char data;
    struct node *left;
    struct node *right;
} node;

node *stack[MAX_STACK_SIZE];
int top = -1;

// Stack operations
void PUSH(node *item) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
    }
    stack[++top] = item;
}

node *POP() {
    if (top < 0) {
        printf("Stack underflow\n");
        return NULL;
    }
    return stack[top--];
}

// Function to create a new node
node *createNode(char x) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Traversal functions
void preorder(node *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

// Function to build expression tree
void exptree(char a[], int isPre) {
    int i;
    for (i = 0; a[i] != '\0'; i++) {
        if (isdigit(a[i]) || isalpha(a[i])) {
            PUSH(createNode(a[i]));
        } else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
            node *left, *right, *New_Node;
            if (isPre) {
                right = POP();
                left = POP();
            } else {
                left = POP();
                right = POP();
            }
            New_Node = createNode(a[i]);
            New_Node->left = left;
            New_Node->right = right;
            PUSH(New_Node);
        }
    }
}

// Function to display the expression tree
void displayTree(node *root) {
    printf("Expression Tree (In-order): ");
    inorder(root);
    printf("\n");
}

// Function to free memory allocated for the tree
void freeTree(node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    char expression[100];
    int choice, isPre;

    do {
        printf("\nMenu:\n");
        printf("1. Enter Expression\n");
        printf("2. Build Expression Tree (Pre-order)\n");
        printf("3. Build Expression Tree (Post-order)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the expression: ");
                scanf("%s", expression);
                break;

            case 2:
                printf("Building Expression Tree (Pre-order)\n");
                isPre = 1;
                exptree(expression, isPre);
                displayTree(stack[0]); // Assuming the result is at the top of the stack
                freeTree(stack[0]);    // Free memory allocated for the tree
                top = -1;              // Reset the stack
                break;

            case 3:
                printf("Building Expression Tree (Post-order)\n");
                isPre = 0;
                exptree(expression, isPre);
                displayTree(stack[0]); // Assume the result is at the top of the stack
                freeTree(stack[0]);    // Free memory allocated for the tree
                top = -1;              // Reset the stack
                break;

            case 4:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}