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

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ar1[i]==ar1[j] &&)
        }
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