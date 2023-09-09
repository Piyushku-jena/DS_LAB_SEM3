#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Infos {
    char title[50];
    char author[50];
    char pub[50];
    int price;
};

int main(){
    int n;
    printf("Enter number of books: ");scanf("%d",&n);
    // struct Infos books[n];

    struct Infos* books = (struct Infos*)malloc(n * sizeof(struct Infos));
    
    if (books == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    
    for(int i=0;i<n;i++){
        printf("Provide input %d:\nTitle: ",i+1);
        scanf("%s",books[i].title);
        printf("Author: ");
        scanf("%s",books[i].author);
        printf("Pub: ");
        scanf("%s",books[i].pub);
        printf("Price: ");
        scanf("%d",&books[i].price);
    }

    char chob[50];

    printf("Particular Author: ");
    scanf("%s",chob);    


    printf("Book Details:\n");

    for (int i=0;i<n;i++){
        int bolav=strcmp(chob,books[i].author);
        if (bolav == 0){
            // printf("yay");
            printf("%d. %s, %s, %s, %d\n",i+1,books[i].title,books[i].author,books[i].pub,books[i].price);
        }
        // printf("%d. %s, %s, %s, %d\n",i+1,books[i].title,books[i].author,books[i].pub,books[i].price);
    }

    free(books);


    return 0;

}