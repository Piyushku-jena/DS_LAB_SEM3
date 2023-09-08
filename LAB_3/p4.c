#include <stdio.h>


int main(){
    int r;
    int counte=0;
    printf("Enter number of row: " );scanf("%d",&r);
    int matrix[r][r];
    for(int rr=0;rr<r;rr++){
        for(int cc=0;cc<r;cc++){
            printf("Input %d row %d column element: ",rr+1,cc+1);
            scanf("%d",&matrix[rr][cc]);

            if(matrix[rr][cc]>0){
            counte++;
            }
        }
    }
    for(int rr=0;rr<r;rr++){
        for(int cc=0;cc<r;cc++){
            printf("%2d ",matrix[rr][cc]);
        }
        printf("\n");
    }

    printf("Number of non-zero elements are: %d\n",counte);


    for(int rr=0;rr<r;rr++){
        int sum=0;
        for(int cc=0;cc<r;cc++){
            sum+=matrix[rr][cc];
        }
        printf("row %d sum: %d\n",rr+1,sum);
    }

    for(int cc=0;cc<r;cc++){
        int sum=0;
        for(int rr=0;rr<r;rr++){
            sum+=matrix[rr][cc];
        }
        printf("column %d sum: %d\n",cc+1,sum);
    }


    return 0;
}


