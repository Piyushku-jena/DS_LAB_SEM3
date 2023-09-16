#include <stdio.h>
#include <stdlib.h>
struct node{
	int info;
	struct node *next;
};
typedef struct node node;

//Prototype Declaration
node *create (node*);
void display(node*);
node *addfirst(node*);
node *addlast(node*);
node *add_specific(node*);
node *deletefirst(node*);
node* deletelast(node*);
node* delete_specific(node*);
void freeLinkedList(node *start);
void count(node *start);

void main(){
	int flag=1, choice;
	node *start=NULL;
	while(flag==1){
	    printf(" 1. Create a node \n");
	    printf(" 2. Display/Traverse \n");
		printf(" 3. Add first \n");
		printf(" 4. Add last \n");
		printf(" 5. Add in any specified position \n");
		printf(" 6. Delete first \n");
		printf(" 7. Delete last \n");
		printf(" 8. Delete any specified position \n");
		printf(" 9. Count number of elements \n");
        printf("10. Delete entire linked list and quit: ");
		
        printf("\nEnter your Choice:");
        scanf("%d", &choice);
        switch(choice){
        case 1: 
            start= create(start); 
            break;
        case 2:
            display(start);
            break;
        case 3: 
            start= addfirst(start);
            break;
        case 4: 
            start= addlast(start);
            break;
        case 5: 
            start= add_specific(start);
            break;
        case 6: 
            start= deletefirst(start);
            break;
        case 7: 
            start= deletelast(start);
            break;
        case 8: 
            start= delete_specific(start);
            break;
        case 9: 
            count(start);
            break;
        case 10:
            freeLinkedList(start);
            printf("Linked list freed.\n");
            flag = 0;
        default:
            printf("Invalid Choice Entered");
            break;
        }
	}
}

//free linkedlist
void freeLinkedList(node *start){
    free(start);
}

//create linkedlist
node *create(node *start){
	node  *newnode, *last;
	char ch;
	int newinfo;
	do{
		printf("Enter the new informaion : ");
		scanf("%d",&newinfo);
		newnode=(node *)malloc(sizeof(node));
		newnode->info=newinfo;
		if(start==NULL){
			start=newnode;
			last= newnode;
            last->next=start;
		}
        else{
	        last->next=newnode;
	        last=newnode;
            newnode->next=start;
        }
        printf("\nDo you want to continue: y/n");
        char trash=getchar();
        ch=getchar();
    }while(ch=='y'||ch=='Y');
    return(start);
}

void display(node* start) {
    if (start == NULL) {
        printf("\nEmpty list...");
        return;
    }
    node* current = start;
    do {
        printf("%d -> ", current->info);
        current = current->next;
        if(current==start){
            break;
        }
    } while (current != start);

    printf("\n");
}
//add first 
node *addfirst(node *start){
	node *newnode;
	int newinfo;
	newnode= (node*) malloc(sizeof(node));
	printf("Enter the new information: ");
	scanf("%d",&newinfo);
	newnode->info=newinfo;
	newnode->next= start;
	start=newnode;
	return(start);
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
	if(start==NULL){
	    start=newnode;
        newnode->next = start;
	    return(start);
	}else{
	    do{
	        last=last->next;
	    }while(last->next!=start);
	    last->next=newnode;
        newnode->next = start;
        return(start);
	}
}
//add specific Position
node *add_specific(node* start){
    node *root, *temp, *newnode;
    int newinfo, p,i;
    printf("Enter the Position where the node is to be inserted");
    scanf("%d",&p);
    printf("Enter the new information: ");
	scanf("%d",&newinfo);
	newnode= (node*) malloc(sizeof(node));
	newnode->info=newinfo;
	newnode -> next=start;
	if(start==NULL||p==1){
	    if (start == NULL) {
            newnode->next=newnode;
        } else {
            node* last = start;
            while (last->next != start) {
                last = last->next;
            }
            last->next = newnode;
            newnode->next=start;
        }
        start = newnode;
	}else{
	    i=1; temp=start;
	    while(i<p && temp->next != start){
	        i++; 
            root=temp; 
            temp=temp->next;
	    }
        newnode->next=temp;
        root->next=newnode;
	}
    return(start);
}

//delete first
node *deletefirst(node *start){
    node *temp;
    temp=start;
    if (temp == NULL){
       printf("\nEmpty list...");
    }
    printf("\nValue of the deleted node = %d",temp->info);
    start=start->next;
    free(temp);
    return(start);
}

// delete last
node* deletelast(node *start){
    node *prev, *last;
    last=start;prev=NULL;
    if (last== NULL){
       printf("\nEmpty list...");
       return(NULL);
    }
    while(last->next!=start){
        prev=last;
        last=last->next;
    }
    printf("\nValue of the deleted node = %d",last->info);
    free(last);
    prev->next=start;
    return(start);
}

// Delete any specified Position
node* delete_specific(node *start){
    node *temp, *prev;
    int delinfo;
    printf("Enter the information to be deleted\n");
    scanf("%d",&delinfo);
    temp=start;
    prev=NULL;
    do{
        if (temp->info == delinfo){
            if (prev == NULL){
                start=deletefirst(start);
            }else{
                prev->next=temp->next;
                free(temp);
            }
            return start;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != start);

    return(start);
}

void count(node* start) {
    if (start == NULL) {
        printf("Total number of Nodes are: 0\n");
        return;
    }
    int c = 1;
    node* current = start->next;
    while (current != start) {
        c++;
        current = current->next;
    }
    printf("Total number of Nodes are: %d\n", c);
}