#include<stdio.h>
int main(){
    char strg[50];     
    int r=0;

    printf("Enter your string: ");
    scanf("%[^\n]s",&strg);
    char* ptr=strg;
    
    while(*ptr!='\0'){
        if (*ptr!=' '){
            r++;
        }
        ptr++;
    }
    printf("The length of your string is %d.\n", r);

}