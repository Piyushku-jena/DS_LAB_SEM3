#include<stdio.h>

#define MAX_SIZE 100  
  
int queue[MAX_SIZE]; 
int front = -1;  
int rear = -1; 

void enqueue();
void dequeue();
void display();


int main(){
    int ch1;
    char ch='y';
    printf("Queue Menu:--------");
    printf("\n 1:Enqueue");
    printf("\n 2:Dequeue");
    printf("\n 3:Display");
    printf("\n 4.Quit");
    while(ch=='y'||ch=='Y'){
        printf("\nEnter your Choice(1,2,3,4):");
        scanf("%d", &ch1);
        switch(ch1){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display(front);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
        printf("\nDo you want to Continue (y/n):");
        scanf(" %c",&ch);
    }
    return 0;
}
  
void enqueue(){
    int item; 
    if (rear == MAX_SIZE - 1) {  
        printf("\nQueue Overflow");  
        return;
    } else {
        if (front == -1) {  
            front = 0;  
        }
        printf("Insert element: ");
        scanf("%d",&item);
    }
    rear++;
    queue[rear] = item;
}  
  
void dequeue() {  
    if (front == -1 || front > rear) {  
        printf("Queue Underflow\n");  
        return;  
    } else {
        printf("Removed element is :%d\n", queue[front]);
        front++;
    }
}
void display(){
    if(front == -1){
        printf("Queue Empty\n");
        return;
    }
    printf("Queue:\n| ");
    for(int i=front;i<=rear;i++){
        if((i==front && i!=rear)||i==(rear-1)){
            printf("%d ",queue[i]);
        }else{
            printf("%d |",queue[i]);
        }
    }
}