#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

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

void reverse_string(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void infix_to_prefix(char* infix, char* prefix) {
    struct Stack stack;
    stack.top = -1;
    int i, j = 0;

    reverse_string(infix);

    for (i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            prefix[j++] = c;
        } else if (c == ')') {
            push(&stack, c);
        } else if (c == '(') {
            while (stack.top != -1 && stack.items[stack.top] != ')') {
                prefix[j++] = pop(&stack);
            }
            if (stack.top != -1 && stack.items[stack.top] == ')') {
                pop(&stack);
            }
        } else {
            while (stack.top != -1 && precedence(c) < precedence(stack.items[stack.top])) {
                prefix[j++] = pop(&stack);
            }
            push(&stack, c);
        }
    }

    while (stack.top != -1) {
        prefix[j++] = pop(&stack);
    }

    prefix[j] = '\0';

    reverse_string(prefix);
}

int main() {
    char infix[100], prefix[100];
    
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    infix_to_prefix(infix, prefix);
    
    printf("Prefix expression: %s\n", prefix);
    
    return 0;
}
