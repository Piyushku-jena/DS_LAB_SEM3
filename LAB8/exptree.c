#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char data;
    struct node *left;
    struct node *right;
} node;

node *stack[MAX_STACK_SIZE];
int top = -1;

void PUSH(node *item) {
    if (top >= MAX_STACK_SIZE - 1) {
        // Stack overflow, handle error
        printf("Stack overflow\n");
    }
    stack[++top] = item;
}
node *POP() {
    if (top < 0) {
        // Stack underflow, handle error
        printf("Stack underflow\n");
    }
    return stack[top--];
}

node* createNode(char x){
    node *temp = (node*)malloc(sizeof(node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void preorder(node* root){
    if(root==NULL){
        printf("Empty tree");
    }else{
        printf("%c ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }
}
void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c ",root->data);
    }
}
void exprtree_post(char a[]){
    int i;
    for(i=0;a[i]!='\0';i++){
        if (isdigit(a[i]) || isalpha(a[i])) {
            PUSH(createNode(a[i]));
        } else if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
            right = POP();
            left = POP();
            New_Node = createNode(a[i]);
            New_Node->left = left;
            New_Node->right = right;
            PUSH(New_Node);
        }
    }
}
void exptree_pre(char a[]){
    int i;
    for(i=0;a[i]!='\0';i++){
        if (isdigit(a[i]) || isalpha(a[i])) {
            PUSH(createNode(a[i]));
        } else if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
            left = POP();
            right = POP();
            New_Node = createNode(a[i]);
            New_Node->left = left;
            New_Node->right = right;
            PUSH(New_Node);
        }
    }
}

// void insert(node **root,char x){
//     if(*root==NULL){
//         *root=createNode(x);
//     }else{
//         if((*root)->data > x){
//             insert(&((*root)->left),x);
//         }else{
//             insert(&((*root)->right),x);
//        }
//     }
// }