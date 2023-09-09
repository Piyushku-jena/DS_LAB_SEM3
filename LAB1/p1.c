#include<stdio.h>

struct Infos {
    int roll;
    char name[20];
    char gender[10];
    int marks;
};

int main(){
    struct Infos stud;
    struct Infos* s1;
    s1=&stud;

    printf("Provide input:\nRoll: ");
    scanf("%d",&s1->roll);
    printf("Name: ");
    scanf("%s",&s1->name);
    printf("Gender: ");
    scanf("%s",&s1->gender);
    printf("Marks: ");
    scanf("%d",&s1->marks);

    printf("Student Details:\nRoll: %d  Name: %s  Gender: %s  Marks: %d\n",s1->roll,s1->name,s1->gender,s1->marks);
    return 0;

}