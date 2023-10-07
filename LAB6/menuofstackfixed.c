// Stack implementation in C

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int count = 0;

// Creating a stack
struct stack {
  int items[MAX];
  int top;
};
typedef struct stack st;

void createEmptyStack(st *s);
int isfull(st *s);
int isempty(st *s);
void push(st *s, int newitem);
void pop(st *s);
void printStack(st *s);
void freeStack(st *s);  // Function to free stack elements
void menu();

// Driver code
void main() {
    int ch;
    st *s = (st *)malloc(sizeof(st));
    createEmptyStack(s);
    menu();
    
    while (1) {
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
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

void menu() {
    printf("\nStack Menu\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");
}

void createEmptyStack(st *s) {
  s->top = -1;
}

// Check if the stack is full
int isfull(st *s) {
  return s->top == MAX - 1;
}

// Check if the stack is empty
int isempty(st *s) {
  return s->top == -1;
}

// Add elements into stack
void push(st *s, int newitem) {
  if (isfull(s)) {
    printf("STACK FULL");
  } else {
    s->top++;
    s->items[s->top] = newitem;
  }
  count++;
}

// Remove element from stack
void pop(st *s) {
  if (isempty(s)) {
    printf("\n STACK EMPTY \n");
  } else {
    printf("Item popped= %d\n", s->items[s->top]);
    s->top--;
  }
  count--;
}

// Print elements of stack
void printStack(st *s) {
  if (isempty(s)) {
        printf("STACK EMPTY\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= s->top; i++){
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

void freeStack(st *s) {
    while (!isempty(s)) {
        pop(s);
    }
    free(s);  // Free the stack itself
}