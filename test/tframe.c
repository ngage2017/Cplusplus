#include <stdio.h>
#include "CircleList.h"

typedef struct Student
{
    CListNode node;
    int age;
    char name[64];
}Student;

int main()
{
    CircleList *list = NULL;
    Student s1,s2,s3;

    s1.age =11;
    s2.age =12;
    s3.age= 13;

    list = CircleList_Create();

    if(list != NULL)
    {
        printf("done\n");
    }

    return 0;
}

