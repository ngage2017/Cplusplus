#include <stdio.h>
#include "LinkList.h"

typedef struct Teacher
{
    LLNode *node;
    int age;
    char name[64];
}Teacher;

int main()
{
    int i = 0,len = 0;
    Teacher t1,t2,t3;
    t1.age = 21;
    t2.age = 22;
    t3.age = 23;

    LinkList *list = NULL;

    list = LinkList_Create();
    
    if(list==NULL)
    {
        printf("list is NULL\n");
    }
    LinkList_Insert(list,(LLNode*)&t1,0);
    LinkList_Insert(list,(LLNode*)&t2,0);
    LinkList_Insert(list,(LLNode*)&t3,0);


    printf("length :%d\n",LinkList_Length(list));

    for(i = 0; i < LinkList_Length(list);i++)
    {
        Teacher *temp = NULL;
        temp = (Teacher *)LinkList_Get(list,i);
        printf("temp->age:%d\n",temp->age);
    
    }
/*LLNode* LinkList_Create();

void LinkList_Destory(LinkList *list);

void LinkList_Clear(LinkList *list);

int LinkList_Length(LinkList* list);

int LinkList_Insert(LinkList* list,LLNode* node,int pos);

LLNode* LinkList_Delete(LinkList* list, int pos);

LLNode* LinkList_Get(LinkList* list,int pos);*/

    printf("Hello world\n");
    return 0;
}

