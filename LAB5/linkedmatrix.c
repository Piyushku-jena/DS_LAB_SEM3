#include <stdio.h>
#include <stdlib.h>

struct node {
    int row;
    int col;
    int val;
    struct node* next;
};
typedef struct node node;

// Prototype Declarations
node* createSparseMatrix(node*);
void displaySparseMatrix(node*);
void freeLinkedList(node*);

int main() {
    node* sparseMatrix = NULL;
    sparseMatrix = createSparseMatrix(sparseMatrix);
    displaySparseMatrix(sparseMatrix);
    freeLinkedList(sparseMatrix);
    return 0;
}

// Free linked list
void freeLinkedList(node* start) {
    node* temp;
    while (start != NULL) {
        temp = start;
        start = start->next;
        free(temp);
    }
}

// Create a sparse matrix
node* createSparseMatrix(node *) {
    node* start = NULL;
    int numRows, numCols;
    node  *newnode, *last;
    
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &numRows, &numCols);

    printf("Enter elements of sparse matrix: ");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int val;
            // printf("Enter the value at (%d, %d): ", i, j);
            scanf("%d", &val);
            if (val != 0) {
                newnode = (node*)malloc(sizeof(node));
                newnode->row = i;
                newnode->col = j;
                newnode->val = val;
                newnode->next = NULL;
                if (start == NULL) {
                    start = newnode;
                    last = newnode;
                } else {
                    last->next = newnode;
                    last = newnode;
                }
            }
        }
    }
    return start;
}

// Display the sparse matrix in 3-tupled format
void displaySparseMatrix(node* start) {
    printf("\nRow\tColumn\tValue\n");
    while (start != NULL) {
        printf("%d\t%d\t%d\n", start->row, start->col, start->val);
        start = start->next;
    }
}