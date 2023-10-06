#include <stdio.h>
#include <stdlib.h>
struct node{
	int info;
	struct node *next;
};
typedef struct node node;

//Prototype Declaration
void display(node*);
node *addlast(node*);
node* deletelast(node*);
void freeLinkedList(node *);
// void count(node *);
// void search(node *);

void main(){	
	int flag=1, choice;
	node *start=NULL;
    printf("Menu: \n");
	printf(" 1. PUSH \n");
	printf(" 2. POP \n");
    printf(" 3. Display/Traverse \n");
	printf(" 4. EXIT \n");
	while(flag==1){
        printf("\nEnter your Choice:");
        scanf("%d", &choice);
        switch(choice){
        case 1: 
            start= addlast(start);
            break;
        case 2:
            start=deletelast(start);
            break;
        case 3:  
            display(start);
            break;
        case 4:
            freeLinkedList(start);
            printf("Linked list freed.\n");
            return;
        default:
            printf("Invalid Choice Entered");
            break;
        }
	}
}

//free linkedlist
void freeLinkedList(node *start) {
    free(start);
}

//display the information of the nodes
void  display( node *start){
	printf("\nBottom->");
	while (start!=NULL){
		printf("--%d",start->info);
		start=start->next;
	}
	printf("--Top\n");
}

// Add last 
node *addlast(node *start){
    node *newnode, *last;
    int newinfo;
    last=start;
    printf("Enter the new information: ");
	scanf("%d",&newinfo);
	newnode= (node*) malloc(sizeof(node));
	newnode->info=newinfo;
	newnode -> next=NULL;
	if(start==NULL){
	    start=newnode;
	    return(start);
	}
	else{
	    while(last->next!= NULL){
	        last=last->next;
	    }
	    last->next=newnode;
	    return(start);
	}
}

// delete last
node* deletelast(node *start){
    node *prev, *last;
    last=start;
    if (last== NULL){
       printf("\nEmpty list...");
       return(NULL);
    }
    while(last->next!=NULL){
        prev=last;
        last=last->next;
    }
    free(last);
    prev->next=NULL;
    return(start);
}
