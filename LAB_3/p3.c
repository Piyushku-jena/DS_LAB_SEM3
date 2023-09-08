#include<stdio.h>
int main(){
    int n,choice,t;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int a[n], b[n];
    printf("Enter array:");
    for(int i=0 ;i < n;++i){
        scanf("%d", &a[i]);
    }

    printf("Select choice: \n1.Traverse\n2.Insert\n3.Delete\n4.Merge\n5.Exit\nEnter choice: ");
    scanf("%d",&choice);
    

    switch(choice){
        case 1:
            printf("Output: ");
            for(int i=0;i<n;i++){
                printf("%d ",a[i]);
            }
            printf("\n");
            break;
        case 2:
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
            printf("Output: ");
            for(int i=0;i<=n;i++){
                printf("%d ",a[i]);
            }
            printf("\n");
            break;
        case 3:
            printf("Enter place to delete and overwrite (1-5) :");
            scanf("%d",&t);
            t=--t;
            for(int j=0;j<5;j++){
                if (j==t){
                    printf("Enter number to be rewritten: ");
                    scanf("%d",&a[j]); 
                }
            }
            printf("Output: ");
            for(int i=0;i<n;i++){
                printf("%d ",a[i]);
            }
            printf("\n");
            break;
        case 4:
            printf("Enter array to merge:");
            for(int i=0 ;i<n;++i){
                scanf("%d",&b[i]);
            }
            break;
        case 5:
            return 0;
        default:
    }
    
    return 0;
}			


    // printf("Input an array: \n");
    // for(int i=0;i<5;i++){
    //     scanf("%d",&a[i]);
    //     b[i]=a[i]+2;
    // }
    // printf("input: \n");
    // for(int i=0;i<5;i++){
    //     printf("%d ",a[i]);
    // }
    // printf("\noutput: \n");
    // for(int i=0;i<5;i++){
    //     printf("%d ",b[i]);
    // }
