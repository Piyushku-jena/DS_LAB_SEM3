#include <stdio.h>
#include <stdlib.h>
struct SparseMatrix;
struct SparseMatrix* createSparseMatrix(int numRows, int numCols, int numNonZero);
void inputSparseMatrix(struct SparseMatrix *matrix);
void printSparseMatrix(struct SparseMatrix *matrix);
struct SparseMatrix* transposeSparseMatrix(struct SparseMatrix *matrix);

int main() {
    int nR, nC, nNZ;
    
    printf("Enter the number of rows, columns, and non-zero elements: ");
    scanf("%d %d %d", &nR, &nC, &nNZ);

    struct SparseMatrix *matrix = createSparseMatrix(nR, nC, nNZ);
    inputSparseMatrix(matrix);

    printf("Original ");
    printSparseMatrix(matrix);

    struct SparseMatrix *transpose = transposeSparseMatrix(matrix);
    printf("Transpose ");
    printSparseMatrix(transpose);

    // Free allocated memory
    free(matrix->rowIndices);
    free(matrix->colIndices);
    free(matrix->data);
    free(matrix);

    free(transpose->rowIndices);
    free(transpose->colIndices);
    free(transpose->data);
    free(transpose);

    return 0;
}

// A structure to represent a sparse matrix
struct SparseMatrix{
    int numRows;
    int numCols;
    int numNonZero;
    int *rowIndices;
    int *colIndices;
    int *data;
};

// Create a sparse matrix in 3-tuple format
struct SparseMatrix* createSparseMatrix(int numRows, int numCols, int numNonZero){
    struct SparseMatrix *matrix = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
    matrix->numRows = numRows;
    matrix->numCols = numCols;
    matrix->numNonZero = numNonZero;

    // Allocate memory for the row indices, column indices, and data
    matrix->rowIndices = (int*)malloc(numNonZero * sizeof(int));
    matrix->colIndices = (int*)malloc(numNonZero * sizeof(int));
    matrix->data = (int*)malloc(numNonZero * sizeof(int));

    return matrix;
}

void inputSparseMatrix(struct SparseMatrix *matrix){
        printf("Enter the elements in row column value format:\n");
    for (int i = 1; i <= numNonZero; i++){
        scanf("%d %d %d", &matrix->rowIndices[i], &matrix->colIndices[i], &matrix->data[i]);
    }
}

// Print a sparse matrix in 3-tuple format
void printSparseMatrix(struct SparseMatrix *matrix){
    for (int i = 0; i < matrix->numNonZero; i++){
        printf("%d %d %d\n", matrix->rowIndices[i], matrix->colIndices[i], matrix->data[i]);
    }
}

struct SparseMatrix* transposeSparseMatrix(struct SparseMatrix *matrix) {
    // Create a new matrix for the transpose
    struct SparseMatrix *transpose = createSparseMatrix(matrix->numCols, matrix->numRows, matrix->numNonZero);

    // Initialize variables to count the number of elements in each column
    int *count = (int*)calloc(matrix->numCols, sizeof(int));

    // Count the number of elements in each column
    for (int i = 0; i < matrix->numNonZero; i++) {
        count[matrix->colIndices[i]]++;
    }

    // Calculate the starting position of each column in the transpose matrix
    int *start = (int*)malloc(matrix->numCols * sizeof(int));
    start[0] = 0;
    for (int i = 1; i < matrix->numCols; i++) {
        start[i] = start[i - 1] + count[i - 1];
    }

    // Populate the transpose matrix
    for (int i = 0; i < matrix->numNonZero; i++) {
        int col = matrix->colIndices[i];
        int pos = start[col];

        transpose->rowIndices[pos] = matrix->colIndices[i];
        transpose->colIndices[pos] = matrix->rowIndices[i];
        transpose->data[pos] = matrix->data[i];

        start[col]++;
    }

    // Free memory allocated for count and start arrays
    free(count);
    free(start);

    return transpose;
}
// // Transpose a sparse matrix in 3-tuple format
// struct SparseMatrix* transposeSparseMatrix(struct SparseMatrix *matrix){
//     struct SparseMatrix *transpose = createSparseMatrix(matrix->numCols, matrix->numRows, matrix->numNonZero);

//     int *count = (int*)calloc(matrix->numCols, sizeof(int));
//     for (int i = 0; i < matrix->numNonZero; i++) {
//         count[matrix->colIndices[i]]++;
//     }

//     // Calculate the starting position of each column in the transpose matrix
//     int *start = (int*)malloc(matrix->numCols * sizeof(int));
//     start[0] = 0;
//     for (int i = 1; i < matrix->numCols; i++) {
//         start[i] = start[i - 1] + count[i - 1];
//     }

//     // Populate the transpose matrix
//     for (int i = 0; i < matrix->numNonZero; i++) {
//         int col = matrix->colIndices[i];
//         int pos = start[col];

//         transpose->rowIndices[pos] = matrix->colIndices[i];
//         transpose->colIndices[pos] = matrix->rowIndices[i];
//         transpose->data[pos] = matrix->data[i];

//         start[col]++;
//     }

//     // Free memory allocated for count and start arrays
//     free(count);
//     free(start);

//     return transpose;
//     // struct SparseMatrix *transpose = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
//     // transpose->numRows = matrix->numCols;
//     // transpose->numCols = matrix->numRows;
//     // transpose->numNonZero = matrix->numNonZero;
// }