#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, searchno;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error. (enter positive integer)\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%dth value: ",i+1);
        scanf("%d", arr+i);
    }

    printf("Enter the element to search: ");
    scanf("%d", &searchno);

    int err = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr+i) == searchno) {
            printf("%d exists at index %d.\n", searchno, i + 1);
            err = 1;
            break;
        }
    }

    if (err==0) {
        printf("%d not found in the array.\n", searchno);
    }


    free(arr);

    return 0;
}
