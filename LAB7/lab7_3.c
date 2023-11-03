#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5 // Maximum size of the circular queue
int front = -1, rear = -1;
int circularQueue[MAX_SIZE];
int isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}
int isEmpty() {
    return (front == -1 && rear == -1);
}
void enqueue(int data) {
    if (isFull()) {
        printf("Circular Queue is full. Cannot insert %d.\n", data);
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        circularQueue[rear] = data;
        printf("%d inserted into the circular queue.\n", data);
    }
}
int dequeue() {
    int data;
    if (isEmpty()) {
        printf("Circular Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        data = circularQueue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("Deleted element: %d\n", data);
        return data;
    }
}
void display() {
    int i;
    if (isEmpty()) {
        printf("Circular Queue is empty.\n");
    } else {
        printf("Circular Queue elements: ");
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", circularQueue[i]);
        }
        printf("%d\n", circularQueue[i]);
    }
}
int main() {
    int choice, data;
    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice (1/2/3/4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
