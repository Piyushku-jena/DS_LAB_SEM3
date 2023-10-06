#include <stdio.h>
#include <stdlib.h>

// Creating a stack
struct stack {
    int *items;
    int top;
    int size;
};
typedef struct stack st;

void createEmptyStack(st *s, int size);
int isfull(st *s);
int isempty(st *s);
void push(st *s, int newitem);
void pop(st *s);
void printStack(st *s);
void freeStack(st *s); 
void menu();

// Driver code
int main() {
    int ch, size;
    
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    
    st *s = (st *)malloc(sizeof(st));
    createEmptyStack(s, size);

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element to push: ");
                int item;
                scanf("%d", &item);
                push(s, item);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                printStack(s);
                break;
            case 4:
                freeStack(s);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void menu() {
    printf("\nStack Menu\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print Stack\n");
    printf("4. Exit\n");
}

void createEmptyStack(st *s, int size) {
    s->top = -1;
    s->size = size;
    s->items = (int *)malloc(size * sizeof(int));
}

int isfull(st *s) {
    return s->top == s->size - 1;
}

int isempty(st *s) {
    return s->top == -1;
}

void push(st *s, int newitem) {
    if (isfull(s)) {
        printf("STACK FULL\n");
    } else {
        s->top++;
        s->items[s->top] = newitem;
        printf("Pushed: %d\n", newitem);
    }
}

void pop(st *s) {
    if (isempty(s)) {
        printf("STACK EMPTY\n");
    } else {
        printf("Popped: %d\n", s->items[s->top]);
        s->top--;
    }
}

void printStack(st *s) {
    if (isempty(s)) {
        printf("STACK EMPTY\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

void freeStack(st *s) {
    free(s->items);
    free(s);
}
