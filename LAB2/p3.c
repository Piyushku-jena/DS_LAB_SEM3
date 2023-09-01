#include<stdio.h>
int main(){
    char name[50];     
    int r=0;

    printf("Enter your name: ");
    scanf("%[^\n]s",&name);
    char* ptr=name;
    
    while(*ptr!='\0'){
        if (*ptr!=' '){
            r++;
        }
        ptr++;
    }
    printf("The length of your string is %d.\n", r);

}