#pragma once

typedef void CircleList;

typedef struct CircleListNode
{
    struct CircleListNode *next;
}CListNode;

CircleList* CircleList_Create();

void CircleList_Destory(CircleList* list);

void CircleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

int CircleList_Insert(CircleList* list,CListNode *node,int pos);

CListNode* CircleList_Get(CircleList* list, int pos);

CListNode* CircleList_Delete(CircleList* list,int pos);

//游标功能

CListNode* CircleList_DeleteNode(CircleList* list,CListNode* node);

CListNode* CircleList_Reset(CircleList *list);

CListNode* CircleList_Current(CircleList* list);

CListNode* CircleList_Next(CircleList* list);


