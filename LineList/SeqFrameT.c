#include <stdio.h>
#include "SeqList.h"

typedef struct Teacher
{
    int age;
    char name[64];
}Teacher;

int main()
{
    int i = 0;
    Teacher t1,t2,t3;
    t1.age = 21;
    t2.age = 22;
    t3.age = 23;

    SeqList* list = NULL;
    list = SeqList_Create(5);

    SeqList_Insert(list,(SeqListNode*)&t1,0);
    SeqList_Insert(list,(SeqListNode*)&t2,0);
    SeqList_Insert(list,(SeqListNode*)&t3,0);

    for(i = 0; i < SeqList_Length(list);i++)
    {
        Teacher *temp = SeqList_Get(list,i);
        printf("temp->age:%d\n",temp->age);
    }

    printf("Hello world\n");

    while(SeqList_Length(list) > 0)
    {
        Teacher *temp  = NULL;
        temp = (Teacher *)SeqList_Delete(list,0);
        printf("Delete:%d\n",temp->age);
    }


    printf("List Capacity:%d\n",SeqList_Capacity(list));
/*SeqList* SeqList_Create(int capacity);

void SeqList_Destory(SeqList *list);

void SeqList_Clear(SeqList *list);

int SeqList_Length(SeqList *list);

int SeqList_Capacity(SeqList *list);

SeqListNode* SeqList_Delete(SeqList* list,SeqListNode *node, int pos);

int SeqList_Insert(SeqList *list, SeqListNode *node, int pos);*/

    return 0;
}

