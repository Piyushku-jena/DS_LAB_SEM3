//  Write a program to create a double linked list and perform the following menu based
// operations on it:
// i. insert an element at specific position
// ii. delete an element from specific position
// iii. Traverse the list


#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prv;
    struct node *next;
};

typedef struct node node;
node *head = NULL;
node* create_node(int x){
    node *temp=(node *)malloc(sizeof(node));
    temp->data = x;
    temp->prv = NULL;
    temp->next = NULL;
    return temp;
}
void insert_at_pos(int pos, int x){
    node *temp=head;
    for (int i=0; i<pos-1; i++){
        temp=temp->next;
    }
    node *temp1=create_node(x);
    temp1->prv=temp;
    temp1->next=temp->next;
    temp->next->prv = temp1;
    temp->next = temp1;
}
void delete_at_pos(int pos){
    node *temp=head;
    for (int i=0; i<pos-1; i++){
        temp=temp->next;
    }
    node *temp1=temp->next;
    temp->next=temp1->next;
    temp1->next->prv=temp;
    free(temp1);
}
void print(){
    node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    // Creating the Linked List
    int ele,n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    
    node *temp=head;
    for (int i=0; i<n; i++){
        if (i==0){
            printf("Enter the data for Node %d: ",i+1);
            scanf("%d",&ele);
            head = create_node(ele);
            temp=head;
            continue;
        }
        node *temp1=NULL;
        // node *temp2=NULL;
        printf("Enter the data for Node %d: ",i+1);
        scanf("%d",&ele);
        temp1 = create_node(ele);
        temp->next = temp1;
        temp1->prv = temp;
        temp=temp->next;
    }
    printf("The Elements of The Linked List:\n\t");
    print();
    
    int ch;
    while (1){
        printf("\n1. Insert at a position\n2. Delete from a position\n3. Traversal\n4. Exit\nChoose:");
        scanf("%d",&ch);
        //Inserting Node at a position
        if (ch==1){
            int pos;
            printf("Enter the data for the Node: ");
            scanf("%d",&ele);
            printf("Enter the position: ");
            scanf("%d",&pos);
            insert_at_pos(pos,ele);
            printf("The List after Insert:\n\t");
            print();
        }
        else if(ch==2){
            int pos;
            printf("Enter the position: ");
            scanf("%d",&pos);
            delete_at_pos(pos);
            print();
        }
        else if (ch==3){
            print();
            printf("The List is traversed.\n");
        }
        else{
            break;
        }
    }
    return 0;
}