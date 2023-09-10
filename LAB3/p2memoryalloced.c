#include <stdio.h>
#include <stdlib.h>
int main(){
int non_zero_count1;
    printf("Enter the number of non zero elements in the matrix-1: ");
    scanf("%d", &non_zero_count1);

    int** arr1 = (int**) malloc((non_zero_count1+1)* sizeof(int*));
    for(int i=0; i<non_zero_count1+1; i++){
        arr1[i] =(int*) malloc(3* sizeof(int));
    }

    if(arr1==NULL){
        printf("memory allocation failed");
    }

    printf("Enter the sparse matrix-1 in 3-tuple format\n");
    for (int i = 0; i < non_zero_count1+1; i++){
        for (int j = 0; j < 3; j++){
            scanf("%d", &arr1[i][j]);
        }
    }

    int non_zero_count2;
    printf("Enter the number of non zero elements in the matrix-2: ");
    scanf("%d", &non_zero_count2);

    int** arr2 = (int**) malloc((non_zero_count2+1)* sizeof(int*));
    for(int i=0; i<non_zero_count2+1; i++){
        arr2[i] =(int*) malloc(3* sizeof(int));
    }

    if(arr2==NULL){
        printf("memory allocation failed");
    }

    printf("Enter the sparse matrix-2 in 3-tuple format\n");
    for (int i = 0; i < non_zero_count2+1; i++){
        for (int j = 0; j < 3; j++){
            scanf("%d", &arr2[i][j]);
        }
    }

    int** sum = (int**) malloc(sizeof(int*));
    sum[0] =(int*) malloc(3* sizeof(int));    

    if(sum==NULL){
        printf("memory allocation failed");
    }

    // now we add the two matrix
    if (arr1[0][0] == arr2[0][0] && arr1[0][1] == arr2[0][1]){
        int k=1,l=1,q=1;
        sum[0][0] = arr1[0][0];
        sum[0][1] = arr1[0][1];
        while (k <= non_zero_count1 && l <= non_zero_count2 ){
            if (arr1[k][0] == arr2[l][0]){
                if (arr1[k][1] == arr2[l][1]){
                    sum = (int**) realloc(sum,(q+1)*sizeof(int*));
                    sum[q] =(int*) malloc(3* sizeof(int));
                    sum[q][0] = arr1[k][0];
                    sum[q][1] = arr1[k][1];
                    sum[q][2] = arr1[k][2] + arr2[l][2];
                    k++, l++, q++;
                } else {
                    if (arr1[k][1] > arr2[l][1]){
                        sum = (int**) realloc(sum,(q+1)*sizeof(int*));
                        sum[q] =(int*) malloc(3* sizeof(int));
                        sum[q][0] = arr2[l][0];
                        sum[q][1] = arr2[l][1];
                        sum[q][2] = arr2[l][2];
                        l++, q++;
                    } else {
                        sum = (int**) realloc(sum,(q+1)*sizeof(int*));
                        sum[q] =(int*) malloc(3* sizeof(int));
                        sum[q][0] = arr1[k][0];
                        sum[q][1] = arr1[k][1];
                        sum[q][2] = arr1[k][2];
                        k++, q++;
                    }
                }
            } else {
                if (arr1[k][0] > arr2[l][0]){
                    sum = (int**) realloc(sum,(q+1)*sizeof(int*));
                    sum[q] =(int*) malloc(3* sizeof(int));
                    sum[q][0] = arr2[l][0];
                    sum[q][1] = arr2[l][1];
                    sum[q][2] = arr2[l][2];
                    l++, q++;
                } else {
                    sum = (int**) realloc(sum,(q+1)*sizeof(int*));
                    sum[q] =(int*) malloc(3* sizeof(int));
                    sum[q][0] = arr1[k][0];
                    sum[q][1] = arr1[k][1];
                    sum[q][2] = arr1[k][2];
                    k++,q++;
                }
            }
        }

        while(k <= non_zero_count1){
            sum = (int**) realloc(sum,(q+1)*sizeof(int*));
            sum[q] =(int*) malloc(3* sizeof(int));
            sum[q][0] = arr1[k][0];
            sum[q][1] = arr1[k][1];
            sum[q][2] = arr1[k][2];
            k++,q++;
        }
        while(l <= non_zero_count2){
            sum = (int**) realloc(sum,(q+1)*sizeof(int*));
            sum[q] =(int*) malloc(3* sizeof(int));
            sum[q][0] = arr2[l][0];
            sum[q][1] = arr2[l][1];
            sum[q][2] = arr2[l][2];
            q++,l++;
        }
        sum[0][2] = q-1;
        printf("The sum sparse matrix 3 tuple form is : \n");
        for (int i = 0; i <q; i++){
            for (int j = 0; j < 3; j++){
            printf("%d  ", sum[i][j]);
            }
            printf("\n");
        }
    }
    // Free memory for arr1
    for (int i = 0; i < non_zero_count1 + 1; i++) {
        free(arr1[i]);
    }
    free(arr1);

    // Free memory for arr2
    for (int i = 0; i < non_zero_count2 + 1; i++) {
        free(arr2[i]);
    }
    free(arr2);

    // Free memory for sum
    for (int i = 0; i < sum[0][2] + 1; i++) {
        free(sum[i]);
    }
    free(sum);

    return 0;
}

/*
Using statically allocated arrays (arrays with fixed sizes determined at compile time) like done in p2.c can work, but it has several limitations and potential drawbacks:

1. **Limited Flexibility**: Statically allocated arrays have fixed sizes, which means you need to know the maximum size in advance. If your matrices can have varying sizes, you might need to allocate more memory than necessary, which can be inefficient.

2. **Stack Size Limitations**: Statically allocated arrays are typically placed on the program's stack, which has limited space. If your matrices are large, you might run into stack overflow issues.

3. **No Dynamic Resizing**: Statically allocated arrays cannot be dynamically resized during runtime. In contrast, dynamically allocated arrays using `malloc` and `realloc` can grow or shrink as needed.

4. **Potential for Buffer Overflow**: If you don't carefully control the sizes of your statically allocated arrays, you risk buffer overflow vulnerabilities if the user inputs data that exceeds the array bounds.

5. **Wasted Memory**: Statically allocated arrays always allocate memory for their maximum size, even if you don't use all of it. This can lead to memory wastage.

In your specific code, you've determined the array sizes based on user input for the number of non-zero elements (`nz1` and `nz2`). This approach can work if you're certain that these sizes will never exceed a certain limit, but it's inflexible for handling matrices of different sizes.

For more flexibility and robust memory management, especially when dealing with matrices of varying sizes or large data, using dynamically allocated memory with `malloc` and `realloc` is generally preferred. Dynamic memory allocation allows your program to adapt to varying input sizes and avoids potential issues related to stack limitations and buffer overflows.

However, if you're confident that your matrices will always be small and you're comfortable with the limitations of statically allocated arrays, your current approach can work for small-scale problems. Just be cautious when handling large or dynamic data sets.
*/