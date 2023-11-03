#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Dequeue {
    struct Node* front;
    struct Node* rear;
};
struct Dequeue* createDequeue() {
    struct Dequeue* dequeue = (struct Dequeue*)malloc(sizeof(struct Dequeue));
    dequeue->front = dequeue->rear = NULL;
    return dequeue;
}
int isEmpty(struct Dequeue* dequeue) {
    return (dequeue->front == NULL);
}
void insertRear(struct Dequeue* dequeue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(dequeue)) {
        dequeue->front = dequeue->rear = newNode;
    } else {
        dequeue->rear->next = newNode;
        dequeue->rear = newNode;
    }
    printf("%d inserted at the rear end.\n", data);
}
void insertFront(struct Dequeue* dequeue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(dequeue)) {
        dequeue->front = dequeue->rear = newNode;
    } else {
        newNode->next = dequeue->front;
        dequeue->front = newNode;
    }
    printf("%d inserted at the front end.\n", data);
}
int deleteFront(struct Dequeue* dequeue) {
    if (isEmpty(dequeue)) {
        printf("Dequeue is empty.\n");
        return -1;
    }
    struct Node* temp = dequeue->front;
    int data = temp->data;
    dequeue->front = temp->next;
    if (dequeue->front == NULL) {
        dequeue->rear = NULL;
    }

    free(temp);
    return data;
}
int deleteRear(struct Dequeue* dequeue) {
    if (isEmpty(dequeue)) {
        printf("Dequeue is empty.\n");
        return -1;
    }
    struct Node* current = dequeue->front;
    int data;
    if (dequeue->front == dequeue->rear) {
        data = dequeue->front->data;
        free(dequeue->front);
        dequeue->front = dequeue->rear = NULL;
    } else {
        while (current->next != dequeue->rear) {
            current = current->next;
        }
        data = dequeue->rear->data;
        free(dequeue->rear);
        dequeue->rear = current;
        current->next = NULL;
    }
    return data;
}
void display(struct Dequeue* dequeue) {
    struct Node* current = dequeue->front;
    if (isEmpty(dequeue)) {
        printf("Dequeue is empty.\n");
        return;
    }
    printf("Dequeue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    struct Dequeue* dequeue = createDequeue();
    int choice, data;
    while (1) {
        printf("\nDequeue Operations:\n");
        printf("1. Insert at rear end\n");
        printf("2. Insert at front end\n");
        printf("3. Delete at front end\n");
        printf("4. Delete at rear end\n");
        printf("5. Display\n");
        printf("6. Quit\n");
        printf("Enter your choice (1/2/3/4/5/6): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at rear end: ");
                scanf("%d", &data);
                insertRear(dequeue, data);
                break;
            case 2:
                printf("Enter data to insert at front end: ");
                scanf("%d", &data);
                insertFront(dequeue, data);
                break;
            case 3:
                data = deleteFront(dequeue);
                if (data != -1) {
                    printf("Deleted element from front end: %d\n", data);
                }
                break;
            case 4:
                data = deleteRear(dequeue);
                if (data != -1) {
                    printf("Deleted element from rear end: %d\n", data);
                }
                break;
            case 5:
                display(dequeue);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
