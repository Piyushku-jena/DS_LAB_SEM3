#include<stdio.h>

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int ar1[n],ar2[n];

    printf("Enter the array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&ar1[i]);
        // ar2[i]=ar1[i];
    }

    int temp=ar1[0]+1;

    for(int i=0;i<n;i++){
        
    }

    printf("Input:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ",ar1[i]);
    }

    printf("\nOutput:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ",ar2[i]);
    }


}