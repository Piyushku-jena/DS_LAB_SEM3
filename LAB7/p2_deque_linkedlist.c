#include <stdio.h>
#include <stdlib.h>
struct node{
	int info;
	struct node *next;
};
typedef struct node node;

struct Dequeue {
    node* front;
    node* rear;
};
typedef struct Dequeue dq;

//Prototype Declaration
dq *create (dq*);
void display(dq*);
dq *addfirst(dq*);
dq *addlast(dq*);
dq *deletefirst(dq*);
dq* deletelast(dq*);
void freeLinkedList(dq *);
int isEmpty(dq*);

void main(){	
	int flag=1, choice;
	dq *dequeue;
    printf("Menu: \n");
    printf(" 1. Create a node \n");
	printf(" 2. Add rear \n");
	printf(" 3. Add front \n");
	printf(" 4. Delete rear \n");
	printf(" 5. Delete front \n");
	printf(" 6. Display \n");
	printf(" 7. Quit: \n");
	while(flag==1){
		
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1: 
            dequeue= create(dequeue); 
            break;
        case 2:
            dequeue= addfirst(dequeue);
            break;
        case 3: 
            dequeue= addlast(dequeue);
            break;
        case 4: 
            dequeue= deletefirst(dequeue);
            break;
        case 5: 
            dequeue= deletelast(dequeue);
            break;
        case 6:
            display(dequeue);
            break;
        case 7:
            freeLinkedList(dequeue);
            printf("Deque freed.\n");
            return;
        default:
            printf("Invalid Choice Entered");
            break;
        }
	}
}

//free linkedlist
void freeLinkedList(dq *dequeue) {
    node* current = dequeue->front;
    if (isEmpty(dequeue)) {
        return;
    }
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }
    printf("\n");
    free(dequeue);
}

//display linkedlist
void display(dq* dequeue) {
    node* current = dequeue->front;
    if (isEmpty(dequeue)) {
        printf("Dequeue is empty.\n");
        return;
    }
    printf("Dequeue elements: ");
    while (current != NULL) {
        printf("%d ", current->info);
        current = current->next;
    }
    printf("\n");
}

//create linkedlist
dq *create(dq *dequeue){
    dequeue = (dq*)malloc(sizeof(dq));
    dequeue->front = dequeue->rear = NULL;
    return (dequeue);
}
int isEmpty(dq* dequeue) {
    return (dequeue->front == NULL);
}
//add first 
dq *addfirst(dq *dequeue){
	int newinfo;
	node *newnode= (node*) malloc(sizeof(node));
	printf("Enter the new information: ");
	scanf("%d",&newinfo);
	newnode -> info=newinfo;
	newnode -> next=NULL;
	if (isEmpty(dequeue)) {
        dequeue->front = dequeue->rear = newnode;
    } else {
        newnode->next = dequeue->front;
        dequeue->front = newnode;
    }
    return(dequeue);
}
// Add last 
dq *addlast(dq *dequeue){
    int newinfo;
    printf("Enter the new information: ");
	scanf("%d",&newinfo);
	node *newnode= (node*) malloc(sizeof(node));
	newnode -> info=newinfo;
	newnode -> next=NULL;
	if(isEmpty(dequeue)){
	    dequeue->front = dequeue->rear = newnode;
	    return(dequeue);
	} else {
	    dequeue->rear->next = newnode;
        dequeue->rear = newnode;
        return(dequeue);
	}
}
//delete first
dq *deletefirst(dq *dequeue){
    if (isEmpty(dequeue)){
       printf("\nEmpty deque...");
       return(NULL);
    }
    node *temp= dequeue->front;
    printf("\nValue of the deleted node = %d",dequeue->rear->info);
    if (dequeue->front == dequeue->rear) {
        free(dequeue->front);
        dequeue->front = dequeue->rear = NULL;
    } else {
        while (temp->next != dequeue->rear) {
            temp = temp->next;
        }
        free(dequeue->rear);
        dequeue->rear = temp;
        temp->next = NULL;
    }
    return(dequeue);
}

// delete last
dq *deletelast(dq *dequeue){
    if (isEmpty(dequeue)){
       printf("\nEmpty deque...");
       return(NULL);
    }
    node *temp= dequeue->front;
    int data=temp->info;
    dequeue->front = temp->next;
    free(temp);
    if(dequeue->front == NULL){
        dequeue->rear = NULL;
    }
    printf("Deleted element: %d\n",data);
    return(dequeue);
}