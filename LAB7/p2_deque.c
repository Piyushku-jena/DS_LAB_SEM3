#include <stdio.h>

#define MAX_SIZE 3

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void insertFront(int);
void insertRear(int);
int removeFront();
int removeRear();
void display();

int main() {
    int ch1, num;
    char ch = 'y';
    printf("Deque Menu:--------");
    printf("\n 1: Insert at Front");
    printf("\n 2: Insert at Rear");
    printf("\n 3: Remove from Front");
    printf("\n 4: Remove from Rear");
    printf("\n 5: Display");
    while (ch == 'y' || ch == 'Y') {
        printf("\nEnter your Choice(1,2,3,4,5):");
        scanf("%d", &ch1);
        switch (ch1) {
            case 1:
                printf("\nEnter a Number: ");
                scanf("%d", &num);
                insertFront(num);
                break;
            case 2:
                printf("\nEnter a Number: ");
                scanf("%d", &num);
                insertRear(num);
                break;
            case 3:
                removeFront();
                break;
            case 4:
                removeRear();
                break;
            case 5:
                display();
                break;
            default:
                printf("Invalid Choice\n");
        }
        printf("\nDo you want to Continue (y/n):");
        // char garbage;
        // scanf(" %c", &garbage); // Added space before %c to skip leading whitespace
        scanf(" %c", &ch); // Added space before %c to skip leading whitespace
    }
    return 0;
}

void insertFront(int element) {
    if (front == (rear+1) % MAX_SIZE) {
        printf("\nDeque is full at the front");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0){
        front = MAX_SIZE-1;
    } else {
        front--;
    }
    queue[front] = element;
}

void insertRear(int item) {
    if (front == (rear+1) % MAX_SIZE) {
        printf("\nDeque is full at the rear");
        return;
    }
    if (front == -1){
        front = rear = 0;
    } else {
        rear = (rear+1) % MAX_SIZE;
    }
    queue[rear] = item;
}

int removeFront() {
    if (front == -1) {
        printf("\nDeque Underflow");
        return -1;
    }
    int element = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return element;
}

int removeRear() {
    if (front == -1) {
        printf("\nDeque Underflow");
        return;
    }
    int element = queue[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0){
        rear = MAX_SIZE - 1;
    } else {
        rear = rear - 1;
    }
    return element;
}

void display() {
    int f = front, r = rear;
    if (front == -1 ) {
        printf("\n Empty Deque...\n");
        return;
    }
    printf("\nThe elements of the Deque are : ");
    if(f <= r){
        while(f <= r) {
            printf("%d ", queue[f]);
            f++;
        }
    } else {
        while(f <= MAX_SIZE-1) {
            printf("%d ", queue[f]);
            f++;
        }
        f = 0;
        while (f <= r) {
        printf("%d ", queue[f]);
        f++;
        } 
    }
    printf("\n");
}

// void display() {
//     if (front == -1) {
//         printf("\nDeque is empty");
//         return;
//     }
//     printf("| ");
//     for (int i = front; i <= rear; i++) {
//         if ((i == front && i != rear) || i == (rear - 1)) {
//             printf("%d ", queue[i]);
//         } else {
//             printf("%d |", queue[i]);
//         }
//     }
// }
