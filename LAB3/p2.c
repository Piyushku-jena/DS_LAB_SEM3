#include <stdio.h>

int main(){
    int r,c,nz1,nz2;
    printf("Enter the required data \nrows: ");
    scanf("%d",&r);
    printf("columns:");
    scanf("%d", &c);
    printf("number of non-zero elements m1:");
    scanf("%d", &nz1);
    printf("number of non-zero elements m2:");
    scanf("%d", &nz2);
    int arr1[nz1+1][3];
    int arr2[nz2+1][3];
    // int tmatrix[nze+1][3];

    arr1[0][0] = r;
    arr1[0][1] = c;
    arr1[0][2] = nz1;
    arr2[0][0] = r;
    arr2[0][1] = c;
    arr2[0][2] = nz2;

    for(int i=1;i<nz1+1;i++){
        printf("Enter row, column and element:");
        scanf("%d %d %d",&arr1[i][0],&arr1[i][1],&arr1[i][2]);
    }
    for(int i=1;i<nz2+1;i++){
        printf("Enter row, column and element:");
        scanf("%d %d %d",&arr2[i][0],&arr2[i][1],&arr2[i][2]);
    }

    for(int rr=0;rr<nz1+1;rr++){
        for(int cc=0;cc<3;cc++){
            printf("%2d ",arr1[rr][cc]);
        }
        printf("\n");
    }
    int qq;
    // now we add the two matrix
    if (arr1[0][0] == arr2[0][0] && arr1[0][1] == arr2[0][1]){
        int k=1,l=1,q=1;
        while (k <= nz1  && l <= nz2 ){
            if (arr1[k][0] == arr2[l][0]){
                if (arr1[k][1] == arr2[l][1]){
                    k++, l++, q++;
                } else {
                    if (arr1[k][1] > arr2[l][1]){
                        l++, q++;
                    } else {
                        k++, q++;
                    }
                }
            } else {
                if (arr1[k][0] > arr2[l][0]){
                    l++, q++;
                } else {
                    k++,q++;
                }
            }
        }
        while(k <= nz1){
            k++,q++;
        }
        while(l <= nz2){
            q++,l++;
        }
        qq=q;
    }
    int sum[qq][3];
    sum[0][2] = qq-1;

    // now we add the two matrix
    if (arr1[0][0] == arr2[0][0] && arr1[0][1] == arr2[0][1]){
        int k=1,l=1,q=1;
        sum[0][0] = arr1[0][0];
        sum[0][1] = arr1[0][1];
        while (k <= nz1  && l <= nz2 ){
            if (arr1[k][0] == arr2[l][0]){
                if (arr1[k][1] == arr2[l][1]){
                    sum[q][0] = arr1[k][0];
                    sum[q][1] = arr1[k][1];
                    sum[q][2] = arr1[k][2] + arr2[l][2];
                    k++, l++, q++;
                } else {
                    if (arr1[k][1] > arr2[l][1]){
                        sum[q][0] = arr2[l][0];
                        sum[q][1] = arr2[l][1];
                        sum[q][2] = arr2[l][2];
                        l++, q++;
                    } else {
                        sum[q][0] = arr1[k][0];
                        sum[q][1] = arr1[k][1];
                        sum[q][2] = arr1[k][2];
                        k++, q++;
                    }
                }
            } else {
                if (arr1[k][0] > arr2[l][0]){
                    sum[q][0] = arr2[l][0];
                    sum[q][1] = arr2[l][1];
                    sum[q][2] = arr2[l][2];
                    l++, q++;
                } else {
                    sum[q][0] = arr1[k][0];
                    sum[q][1] = arr1[k][1];
                    sum[q][2] = arr1[k][2];
                    k++,q++;
                }
            }
        }
        while(k <= nz1){
            sum[q][0] = arr1[k][0];
            sum[q][1] = arr1[k][1];
            sum[q][2] = arr1[k][2];
            k++,q++;
        }
        while(l <= nz2){
            sum[q][0] = arr2[l][0];
            sum[q][1] = arr2[l][1];
            sum[q][2] = arr2[l][2];
            q++,l++;
        }
    }
    printf("The sum sparse matrix 3 tuple form is : \n");
    for (int i = 0; i < qq; i++){
        for (int j = 0; j < 3; j++){
        printf("%d  ", sum[i][j]);
        }
        printf("\n");
    }
    return 0;

}