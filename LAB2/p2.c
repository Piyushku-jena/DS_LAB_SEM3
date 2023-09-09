#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int arr[n],u_e[n];
    printf("Enter the array elements: ");
    for(int i=0 ;i<n;++i){
        scanf("%d", &arr[i]);
    }
    printf("%d\n",n);

    int u_e_c = 0;

    for (int i = 0; i < n; i++) {

        int is_unique = 1;
        for (int j = 0; j < u_e_c; j++) {
            if (arr[i] == u_e[j]) {
                is_unique = 0;
                break;
            }
        }

        if (is_unique) {
            u_e[u_e_c] = arr[i];
            u_e_c++;
        }
    }

    printf("Array with distinct elements: ");
    for (int i = 0; i < u_e_c; i++) {
        printf("%d ", u_e[i]);
    }
    printf("\n");
    return 0;
}
