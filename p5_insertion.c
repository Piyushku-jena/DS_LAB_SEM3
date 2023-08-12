#include<stdio.h>

int main(){
    int a[5], b[5];
    printf("enter: \n");
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
            if(a[k]>a[k+1]){
                int temp=a[k+1];
                a[k+1]=a[k];
                a[k]=temp;
            }
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