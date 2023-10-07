#include<stdio.h>

#define MAX_SIZE 100  
  
int queue[MAX_SIZE]; 
int front = -1;  
int rear = -1; 

void enqueue(int);
int dequeue();
void display();


int main(){  
    // enqueue(10);  
    // enqueue(20);  
    // enqueue(30);  
    // printf("%d ", dequeue());  
    // printf("%d ", dequeue());  
    // printf("%d ", dequeue());  
    // printf("%d ", dequeue());  
    // return 0;
    int ch1, num;
    char ch='y';
    printf("Queue Menu:--------");
    printf("\n 1:Enqueue");
    printf("\n 2:Dequeue");
    printf("\n 1:Display");
    while(ch=='y'||ch=='Y'){
        printf("\nEnter your Choice(1,2,3,4):");
        scanf("%d", &ch1);
        switch(ch1){
            case 1:
                printf("\nEnter a Number: ");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display(front);
                break;
            default:
                printf("Invalid Choice\n");
        }
        printf("\nDo you want to Continue (y/n):");
        char garbage;
        scanf("%c",&garbage);
        scanf("%c",&ch);
    }
    return 0;
}
  
void enqueue(int element) {  
    if (rear == MAX_SIZE - 1) {  
        printf("\nQueue is full");  
        return;  
    }  
    if (front == -1) {  
        front = 0;  
    }  
    rear++;  
    queue[rear] = element;  
}  
  
int dequeue() {  
    if (front == -1 || front > rear) {  
        printf("\nQueue is empty");  
        return -1;  
    }  
    int element = queue[front];  
    front++;  
    return element;  
}
void display(){
    printf("| ");
    for(int i=front;i<=rear;i++){
        if((i==front && i!=rear)||i==(rear-1)){
            printf("%d ",queue[i]);
        }else{
            printf("%d |",queue[i]);
        }
    }
}