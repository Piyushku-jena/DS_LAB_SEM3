#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void push(struct Stack*,char);
int pop(struct Stack*);
int is_operator(char);
int precedence(char);
int infix_to_postfix;

int main() {
    char infix[100], postfix[100];
    
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    infix_to_postfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}

void push(struct Stack* stack, char c) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = c;
}

char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infix_to_postfix(char* infix, char* postfix) {
    struct Stack stk;
    stk.top = -1;
    int i, j = 0;

    for (i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (stk.top != -1 && stk.items[stack.top] != '(') {
                postfix[j++] = pop(&stk);
            }
            if (stk.top != -1 && stk.items[stack.top] == '(') {
                pop(&stk);
            }
        } else {
            while (stk.top != -1 && precedence(c) <= precedence(stk.items[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, c);
        }
    }

    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}
