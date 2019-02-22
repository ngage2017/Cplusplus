#include <stdio.h>
#include "DLinkList.h"

typedef struct Teacher
{
    DLLNode node;
    int age;
}Teacher;

int main()
{
    int i = 0;
    DLinkList *list = NULL;
    Teacher t1,t2,t3,t4,t5,*ret;
    t1.age = 11;
    t2.age = 12;
    t3.age = 13;
    t4.age = 14;
    t5.age = 15;

    list = DLinkList_Create();
    if(list == NULL)
    {
        printf("List is NULL\n");
    }

    DLinkList_Insert(list,(DLLNode *)&t1,DLinkList_Length(list));
    DLinkList_Insert(list,(DLLNode *)&t2,DLinkList_Length(list));
    DLinkList_Insert(list,(DLLNode *)&t3,DLinkList_Length(list));
    DLinkList_Insert(list,(DLLNode *)&t4,DLinkList_Length(list));
    DLinkList_Insert(list,(DLLNode *)&t5,DLinkList_Length(list));
   
    for(i = 0; i < DLinkList_Length(list); i++)
    {
        Teacher *temp =(Teacher *) DLinkList_Get(list,i);
        printf("temp->age:%d\n",temp->age);
    }

    printf("===================>\n");
    ret = (Teacher *)DLinkList_Current(list);
    printf("current->age:%d\n",ret->age);
    ret = (Teacher *)DLinkList_Next(list);
    printf("pre->age:%d\n",ret->age);
    ret = (Teacher *)DLinkList_Current(list);
    printf("current->age:%d\n",ret->age);
                         
    return 0;
}

