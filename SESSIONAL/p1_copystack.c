#include <stdio.h>
#include <stdlib.h>

#define MAX 4

struct stack {
  int items[MAX];
  int top;
};
typedef struct stack st;

void copystack(st *s,st *t);
void push(st *s, int item);
int pop(st *s);
void display(st *s);
void freeStack(st *s);


int main() {
    st *s = (st *)malloc(sizeof(st));s->top=-1;
    st *t = (st *)malloc(sizeof(st));t->top=-1;
    printf("Enter the elements of first stack: ");
    for (int i=0;i<=3;i++) {
        scanf("%d",&s->items[++s->top]);
    }
    copystack(s,t);
    display(t);
    freeStack(s);
    freeStack(t);
    return 0;
}

void push(st *s, int newitem) {
  if (s->top == MAX - 1) {
    printf("\noverflow\n");
  } else {
    s->top++;
    s->items[s->top] = newitem;
  }
}

int pop(st *s) {
    int temp;
  if (s->top == -1) {
    printf("\nunderflow\n");
  } else {
    temp = s->items[s->top];
    s->top--;
  }
  return temp;
}

void display(st *p) {
    int temp;
    if (p->top == -1){
        printf("STACK EMPTY\n");
    } else {
        temp=pop(p);
        display(p,q);
        printf("%d ",temp);
        push(p,temp);
    }  
}

void copystack(st * p,st* q){
    int temp;
    if(p->top == -1){
        return;
    } else {
        temp=pop(p);
        copystack(p,q);
        push(q,temp);
        push(p,temp);
    }
}

void freeStack(st *s) {
    while (!isempty(s)) {
        pop(s);
    }
    free(s);
}