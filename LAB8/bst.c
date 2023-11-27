#include<stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node;

node* insert(node** root, int value);
void inorder_traversal(node* root);
void preorder_traversal(node* root);
void postorder_traversal(node* root);
node* delete(node* root, int value);
node* Search(node* root, int x);
int findMin(node* root);
int findMax(node* root);
void clearMemory(node* root);

int main() {
    node* root = NULL;
    int choice, value;
    printf("\n1. Insert \n2. Search \n3. Inorder Traversal \n4. Preorder Traversal \n5. Postorder Traversal\n6. Find Minimum \n7. Find Maximum \n8. Delete \n9. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(&root, value);
                break;

            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                Search(root, value);
                // if (Search(root, value) != NULL) {
                //     printf("Element found in the tree.\n");
                // } else {
                //     printf("Element not found in the tree.\n");
                // }
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder_traversal(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorder_traversal(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorder_traversal(root);
                printf("\n");
                break;

            case 6:
                printf("Largest element: ");
                printf("%d\n", findMax(root));
                break;

            case 7:
                printf("Smallest element: ");
                printf("%d\n", findMin(root));
                break;
            
            case 8:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
                break;
            
            case 9:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    clearMemory(root);

    return 0;
}

void clearMemory(node* root) {
    if (root != NULL) {
        clearMemory(root->left);
        clearMemory(root->right);
        free(root);
    }
}

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
        printf("%d ",root->data);
    }
}
node* delete(node* root,int value){
    if(root==NULL){
        printf("Element not found\n");
        return root;
    } else if(root->data < value){
        root->left = delete(root->left,value);
    } else if(root->data >value){
        root->right = delete(root->right,value);
    } else if (root->left && root->right){
        int minVal = findMin(root->right);
        root->data = minVal;
        root->right = delete(root->right ,minVal);
    } else {
        if(root->left==NULL){
            node *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        }
    }
    return root;
}
node* Search(node *root, int x){
    if (root== NULL){
        printf("\n No element in the tree");
        return root;
    } else if ( root->data == x ){
       return root;
    } else if ( x < root->data ){
        return Search(root->left,x);
    } else {
        return Search(root->right,x);
    }
}
int findMin(node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}
int findMax(node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}
