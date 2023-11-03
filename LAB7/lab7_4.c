#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct CircularQueue {
    struct Node* front;
    struct Node* rear;
};
struct CircularQueue* createCircularQueue() {
    struct CircularQueue* circularQueue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    circularQueue->front = circularQueue->rear = NULL;
    return circularQueue;
}
int isEmpty(struct CircularQueue* circularQueue) {
    return (circularQueue->front == NULL);
}
//fucntion for insertion
void enqueue(struct CircularQueue* circularQueue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(circularQueue)) {
        circularQueue->front = circularQueue->rear = newNode;
        newNode->next = circularQueue->front; // Circular link
    } else {
        circularQueue->rear->next = newNode;
        newNode->next = circularQueue->front; // Circular link
        circularQueue->rear = newNode;
    }
    printf("%d inserted into the circular queue.\n", data);
}
//function fopr deletion
int dequeue(struct CircularQueue* circularQueue) {
    int data;
    if (isEmpty(circularQueue)) {
        printf("Circular Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        struct Node* temp = circularQueue->front;
        data = temp->data;
        if (circularQueue->front == circularQueue->rear) {
            circularQueue->front = circularQueue->rear = NULL;
        } else {
            circularQueue->front = temp->next;
            circularQueue->rear->next = circularQueue->front; // Update circular link
        }
        free(temp);
        printf("Deleted element: %d\n", data);
        return data;
    }
}
//function for displaying
void display(struct CircularQueue* circularQueue) {
    struct Node* current = circularQueue->front;
    if (isEmpty(circularQueue)) {
        printf("Circular Queue is empty.\n");
    } else {
        printf("Circular Queue elements: ");
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != circularQueue->front);
        printf("\n");
    }
}
int main() {
    struct CircularQueue* circularQueue = createCircularQueue();
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
                enqueue(circularQueue, data);
                break;
            case 2:
                dequeue(circularQueue);
                break;
            case 3:
                display(circularQueue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
