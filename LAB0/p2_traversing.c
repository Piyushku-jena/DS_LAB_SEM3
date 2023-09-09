#include<stdio.h>
// traversing
int main(){
    int a[5], b[5];
    printf("Input an array: \n");
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
        b[i]=a[i]+2;
    }
    printf("input: \n");
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    printf("\noutput: \n");
    for(int i=0;i<5;i++){
        printf("%d ",b[i]);
    }
    return 0;
}