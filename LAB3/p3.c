#include<stdio.h>
#include<stdlib.h>

int* sum_polynomial(int*arr1,int*arr2,int D3){
    int* arr3 = (int*) calloc(D3 ,sizeof(int));
    for(int i=0; i<=D3; i++){
        arr3[i]=arr1[i]+arr2[i];
    }
    return arr3;
} 

int main() {
    int D1,D2;
    printf("Enter the degree of 1st and 2nd polynomial respectively: ");
    scanf("%d %d",&D1,&D2);
    int D3=(D1>D2)? D1:D2;
    printf(" %d \n",D3);
    int* arr1 = (int*) calloc((D3+1),sizeof(int));
    int* arr2 = (int*) calloc((D3+1),sizeof(int));
    printf("Enter Polynomials from lowest degree to highest degree (Hint: 4+2x+3x^2)\n");
    printf("Enter Polynomial-1: ");
    for(int i=0; i<=D1; i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter Polynomial-2: ");
    for(int i=0; i<=D2; i++){
        scanf("%d",&arr2[i]);
    }
    
    int *sum=sum_polynomial(arr1,arr2,D3);

    printf("The added polynomial\n");
    for(int i=0; i<=D3; i++){
        printf("%dx^%d ",sum[i],i);
        printf((i==D3)? "":"+ ");
        // printf("%d ",sum[i]);
    }
    free(arr1);
    free(arr2);
    free(sum);
    return 0;

}