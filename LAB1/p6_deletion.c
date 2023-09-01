#include<stdio.h>

int main(){
    int a[5], b[5];
    int t;
    printf("enter: \n");
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }

    printf("Enter place to ovrwrite (1-5) :");
    scanf("%d",&t);
    t=--t;

    for(int j=0;j<5;j++){
        
        if (j==t){
            printf("Enter number to be rewritten: ");
            scanf("%d",&a[j]);
            
        }
        
    }
    printf("input: \n");
    for(int i=0;i<5;i++){
        printf("%d ",b[i]);
    }
    printf("\noutput: \n");
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
}