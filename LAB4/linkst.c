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
node* reverse(node *); 
void main(){
	
	int flag=1, choice;
	node *start=NULL;
	while(flag==1){
	    printf("Press 1 to create a node \n");
	    printf("Press 2 to  display/Traverse \n");
		printf("Press 3 to  add first \n");
		printf("Press 4 to  add last \n");
		printf("Press 5 to  add in any specified position \n");
		printf("Press 6 to  delete first \n");
		printf("Press 7 to  delete last \n");
		printf("Press 8 to  delete any specified position \n");
		printf("Press 9 to  search an element \n");
		printf("Press 10 to  count number of elements \n");
		printf("Press 11 to  reverse a linklist \n");
		printf("Press 12 to  traverse \n");
		
        printf("Enter your Choice:");
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
            start= search(start);
            break;
        case 10: 
            start= count(start);
            break;
        case 11: 
            start= reverse(start);
            break;
        case 12: 
            start= travaerse(start);
            break;
        
        default:
            printf("Invalid Choice Entered");
            break;
        }
	}

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
		newnode->next=NULL;
		if(start==NULL){
			start= newnode;
			last=newnode;
		}
        else{
	        last->next= newnode;
	        last=newnode;
        }
        printf("\n do you want to continue:  y/n \n");
        ch=getch();
    }while(ch=='y'||ch=='Y');
    return(start);
}

//display the information of the nodes
void  display( node *start){
	printf("\n Start->");
	while (start!=NULL){
		printf("--%d",start->info);
		start=start->next;
	}
	printf("-End");
}
//add first 
node *addfirst(node *start){
	node *newnode;
	int newinfo;
	newnode= (node*) malloc(sizeof(node));
	printf("Enter the newinformation");
	scanf("%d",&newinfo);
	newnode->info=newinfo;
	newnode -> next= start;
	start=newnode;
	return(start);
}
// Add last 
node *addlast(node *start){
    node *newnode, *last;
    int newinfo;
    last=start;
    printf("Enter the newinformation");
	scanf("%d",&newinfo);
	newnode= (node*) malloc(sizeof(node));
	newnode->info=newinfo;
	newnode -> next=NULL;
	if(start==NULL){
	    start=newnode;
	    return(start);
	}
	else{
	    while(last->next!= NULL)
	    {
	        last=last->next;
	    }
	    last->next=newnode;
	    return(start);
	}
}
//add specific Position
node *add_specific(node* start){
    node *root, *temp, *newnode;
    int newinfo, p,i;
    printf("Enter the Position where the node is to be inserted");
    scanf("%d",&p);
    printf("Enter the newinformation");
	scanf("%d",&newinfo);
	newnode= (node*) malloc(sizeof(node));
	newnode->info=newinfo;
	newnode -> next=NULL;
	if(start==NULL||p==1){
	    newnode->next=start;
	    start=newnode;
	    return(start);
	}else{
	    i=1; temp=start;
	    while(i<p && temp->next != NULL){
	        i++; root=temp; temp=temp->next;
	    }
	    if(temp->next=NULL){
	        temp->next=newnode;
	    }
	    else{
	        newnode->next=temp; root->next=newnode;
	    }
	    
	}
    return(start);
}

//delete first
node *deletefirst(node *start){
    node *temp;
    temp=start;
    if (temp == NULL) 
    {
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

// Delete any specified Position
node* delete_specific(node *start){
    node *temp, *prev;
    int delinfo;
    printf("Enter the information to be deleted\n");
    scanf("%d",&delinfo);
    temp=start;
    prev=NULL;
    if(start==NULL){
        printf("\nEmpty list...");
        return(NULL);
    }
    if(temp->info==delinfo && prev==NULL){
        start=temp->next;
        free(temp);
        return(start);
    }
    while(temp->info !=delinfo && temp->next!= NULL){
        prev=temp;
        temp=temp->next;
    }
    if(temp->info==delinfo){
        prev->next=temp->next;
        free(temp);
    }
    return(start);    
}

node* reverse(node *start) { 
    node* prev = NULL, *ptr; 
    node* curr=start; 
    if(start==NULL){
      printf("\nEmpty List ...");
      return(NULL);
    }
    while (curr != NULL){
        ptr = curr->next;   
        curr->next = prev;    
        prev = curr; 
        curr = ptr; 
    } 
    start = prev; 
}
