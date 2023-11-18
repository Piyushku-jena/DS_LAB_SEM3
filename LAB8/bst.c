#include<stdio.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node;

node* insert(node **root,int value){
    if(*root == NULL){
        (*root) = (node*)malloc(sizeof(node));
        (*root)->data=value;
        (*root)->left=NULL;
        (*root)->right=NULL;
    }else{
        if((*root)->data > value){
            insert(&((*root)->left),value);
        }else{
            insert(&((*root)->right),value);
        }
    }
    return *root;
}
void inorder_traversal(node *root){
    if(root != NULL){
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}
void preorder_traversal(node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}
void postorder_traversal(node *root){
    if(root!=NULL){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d",root->data);
    }
}
node* delete(node* root,int value){
    
}