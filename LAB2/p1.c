#include<stdio.h>

int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);

    int ar1[n],ar2[n];

    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&ar1[i]);
        ar2[n-i-1]=ar1[i];
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