#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
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
        scanf("%d", &arr[i]);
    }

    int smol = arr[0];
    int big = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < smol) {
            smol = arr[i];
        }
        if (arr[i] > big) {
            big = arr[i];
        }
    }

    printf("Smallest: %d  and Largest: %d\n", smol,big);
    
    free(arr);

    return 0;
}
