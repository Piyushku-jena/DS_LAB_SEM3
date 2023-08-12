#include<stdio.h>

int main(){
    int a[5], item, i;
    printf("enter: \n");
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    printf("Item to search: ");
    scanf("%d",&item);
    for(i=0;i<5;i++){
        if(a[i]==item){
            printf("Element position: %d",i+1);
            break;
        }
    }
    if(i==5){
        printf("Item not found.\n");
    }
}