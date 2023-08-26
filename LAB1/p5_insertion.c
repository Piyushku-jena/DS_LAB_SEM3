#include<stdio.h>

int main(){
    int a[5], b[5];
    int t;
    printf("enter: \n");
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }

    printf("Enter place of insertion (1-6) :");
    scanf("%d",&t);
    t=--t;

    for(int j=5;j>=t;j--){
        
        if(j>t){
            a[j]=a[j-1];
        } else if (j==t){
            printf("Enter number to be inserted: ");
            scanf("%d",&a[j]);
        }
        
    }
    printf("input: \n");
    for(int i=0;i<5;i++){
        printf("%d ",b[i]);
    }
    printf("\noutput: \n");
    for(int i=0;i<6;i++){
        printf("%d ",a[i]);
    }
}