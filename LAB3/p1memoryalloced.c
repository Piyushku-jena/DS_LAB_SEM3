#include<stdio.h>
#include<stdlib.h>

int** transpose(int** sparse_matrix, int n){
    int** transpose_matrix = (int**) malloc((n)* sizeof(int*));
    for(int i=0; i<n; i++){
        transpose_matrix[i] =(int*) malloc(3* sizeof(int));
    }

    if(transpose_matrix==NULL){
        printf("memory allocation failed");
    }
    int k=1;
    transpose_matrix[0][0]=sparse_matrix[0][1];
    transpose_matrix[0][1]=sparse_matrix[0][0];
    transpose_matrix[0][2]=sparse_matrix[0][2];
    for (int i = 0; i < sparse_matrix[0][1] ; i++) {
        for(int j = 1; j < n ; j++){
            if(sparse_matrix[j][1]==i){
                transpose_matrix[k][0]=sparse_matrix[j][1];
                transpose_matrix[k][1]=sparse_matrix[j][0];
                transpose_matrix[k][2]=sparse_matrix[j][2];
                k++;
            }
        }
    }
    return transpose_matrix;
}


int main() {
    int non_zero_count;
    printf("Enter the number of non zero elements in the matrix: ");
    scanf("%d", &non_zero_count);


    int** sparse_matrix = (int**) malloc((non_zero_count+1)* sizeof(int*));
    for(int i=0; i<non_zero_count+1; i++){
        sparse_matrix[i] =(int*) malloc(3* sizeof(int));
    }

    if(sparse_matrix==NULL){
        printf("memory allocation failed");
    }

    printf("Enter the sparse matrix in 3-tuple format\n");
    for (int i = 0; i < non_zero_count+1; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &sparse_matrix[i][j]);
        }
    }
    int** transpose_matrix=transpose(sparse_matrix,non_zero_count+1);

    printf("\n3-Tuple representation of the transpose sparse matrix:\n");
    for (int i = 0; i <= non_zero_count; i++) {
        for(int j=0; j<3; j++){
            printf("%d ", transpose_matrix[i][j]);
        }
        printf("\n");
    }
    free(sparse_matrix);
    free(transpose_matrix);

    return 0;
}