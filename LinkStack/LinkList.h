#pragma once

typedef void LinkList;

typedef struct LinkListNode
{
    struct LinkListNode *next;
}LLNode;

LinkList* LinkList_Create();

void LinkList_Destory(LinkList *list);

void LinkList_Clear(LinkList *list);

int LinkList_Length(LinkList* list);

int LinkList_Insert(LinkList* list,LLNode* node,int pos);

LLNode* LinkList_Delete(LinkList* list, int pos);

LLNode* LinkList_Get(LinkList* list,int pos);
