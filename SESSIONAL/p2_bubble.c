#include<stdio.h>

void Bubble(int a[],int n);

int main(){
    int arr[] = {6,8,5,9,1,67,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original array is : \n");
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nSorted array in ascending order: \n");
    Bubble(arr,n);
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}


void Bubble(int a[], int n){
    int temp, itr,i;
    for (itr=0; itr<n-1; itr++){
        for (i=0; i<n-itr-1; i++){
            if (a[i] > a[i+1]){ 
                temp= a[i];
                a[i] = a[i+1];
                a[i+1]= temp;
            }
        }
    }
}