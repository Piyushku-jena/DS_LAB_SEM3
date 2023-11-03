#include <stdio.h>

#define MAX_SIZE 3

typedef struct queue {
int cque[MAX_SIZE];
int rear;
int front;
}CQueue;

void insert(CQueue *cq);
void delete(CQueue *cq);
void display(CQueue cq);

void main(){
    int ch1;
    CQueue cq;
    cq.rear = cq.front = -1;
    char ch = 'y';
    printf("Deque Menu:--------");
    printf("\n 1: Insert");
    printf("\n 2: Delete");
    printf("\n 3: Display");
    printf("\n 4: Quit");
    while (ch == 'y' || ch == 'Y') {
        printf("\nEnter your Choice(1,2,3,4):");
        scanf("%d", &ch1);
        switch (ch1) {
            case 1:
                insert(&cq);
                break;
            case 2:
                delete(&cq);
                break;
            case 3:
                display(cq);
                break;
            case 4:
                return;
            default:
                printf("Invalid Choice\n");
        }
        printf("\nDo you want to Continue (y/n):");
        scanf(" %c", &ch);
    }
    return;
}


void insert(CQueue *cq){
    if (cq->front == (cq->rear+1) % MAX_SIZE) {
        printf("\nDeque Overflow");
        return;
    }
    int item;
    printf("Enter item: ");
    scanf("%d",&item);
    if (cq->front == -1){
        cq->front = cq->rear = 0;
    } else {
        cq->rear = (cq->rear+1) % MAX_SIZE;
    }
    cq->cque[cq->rear] = item;
}


void delete(CQueue *cq) {
    if (cq->front == -1) {
        printf("Cqueue Underflow\n");
        return;
    }
    printf("Item : %d\n", cq->cque[cq->front]);
    if (cq->front == cq->rear) {
        cq->front = cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % MAX_SIZE;
    }
    return;
}

void display(CQueue cq) {
    int i;
    if (cq.front == -1 ) {
        printf("\n Empty Cqueue...\n");
        return;
    }
    printf("\nThe elements of the Cqueue are : ");
    // printf("\nFront -> %d\n", cq.front);
    printf("Elements -> ");
    for(i = cq.front; i != cq.rear; i= (i+1) % MAX_SIZE){
        printf("%d ", cq.cque[i]);
    }
    printf("%d\n", cq.cque[i]);
    // printf("Rear -> %d\n", cq.rear);
    printf("\n");
}