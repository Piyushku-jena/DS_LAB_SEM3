#include <stdio.h>

int main(){
    int r,c,nze;
    printf("Enter the required data \nrows: ");
    scanf("%d",&r);
    printf("columns:");
    scanf("%d", &c);
    printf("number of non-zero elements:");
    scanf("%d", &nze);
    int matrix[nze+1][3];
    int tmatrix[nze+1][3];

    matrix[0][0] = r;
    matrix[0][1] = c;
    matrix[0][2] = nze;
    tmatrix[0][0] = c;
    tmatrix[0][1] = r;
    tmatrix[0][2] = nze;

    for(int i=1;i<nze+1;i++){
        printf("Enter row, column and element:");
        scanf("%d %d %d",&matrix[i][0],&matrix[i][1],&matrix[i][2]);
    }

    for(int rr=0;rr<nze+1;rr++){
        for(int cc=0;cc<3;cc++){
            printf("%2d ",matrix[rr][cc]);
        }
        printf("\n");
    }
    int k=1;
    for (int i=0;i<=matrix[0][1];i++){
        for(int j=1;j<=nze+1;j++){
            if(matrix[j][1]==i){
                tmatrix[k][0]=matrix[j][1];
                tmatrix[k][1]=matrix[j][0];
                tmatrix[k][2]=matrix[j][2];
                k++;
            }
        }
    }
    printf("Transpose: \n");
    for(int rr=0;rr<nze+1;rr++){
        for(int cc=0;cc<3;cc++){
            printf("%2d ",tmatrix[rr][cc]);
        }
        printf("\n");
    }
    return 0;

}