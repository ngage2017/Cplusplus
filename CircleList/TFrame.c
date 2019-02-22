#include <stdio.h>
#include "CircleList.h"

typedef struct Teacher
{
    CListNode node;
    int age;
}Teacher;

typedef struct Student
{
    CListNode node;
    int ID;
}Student;

int main()
{
    int i= 0,len = 0;
    CircleList *list = NULL;
    Student s1,s2,s3,s4,s5,s6,s7,s8;
    s1.ID = 1; s2.ID = 2;s3.ID = 3;s4.ID = 4; s5.ID = 5;s6.ID = 6;
    s7.ID = 7; s8.ID = 8;

    list = CircleList_Create();
    if(list == NULL)
    {
        printf("list is NULL\n");
    }


    CircleList_Insert(list,(CListNode *)&s1,CircleList_Length(list));
    CircleList_Insert(list,(CListNode *)&s2,CircleList_Length(list));
    CircleList_Insert(list,(CListNode *)&s3,CircleList_Length(list));
    CircleList_Insert(list,(CListNode *)&s4,CircleList_Length(list));
    CircleList_Insert(list,(CListNode *)&s5,CircleList_Length(list));
    CircleList_Insert(list,(CListNode *)&s6,CircleList_Length(list));
    CircleList_Insert(list,(CListNode *)&s7,CircleList_Length(list));
    CircleList_Insert(list,(CListNode *)&s8,CircleList_Length(list));

    for(i = 0; i < CircleList_Length(list); i++)
    {
        Student *temp =(Student *) CircleList_Next(list);
        printf("temp->ID:%d\n",temp->ID);
    }

    CircleList_Reset(list);

    while(CircleList_Length(list) > 0)
    {
        Student *ret = NULL;
        for(i = 1; i < 3 ; i++)
        {
            CircleList_Next(list);
        }
        ret = (Student *)CircleList_Current(list);
        printf("ret->ID:%d\n",ret->ID);
        CircleList_DeleteNode(list,(CListNode *)ret);
    }

    CircleList_Destory(list);
    return 0;
}

