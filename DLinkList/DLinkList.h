#pragma once

typedef void DLinkList;

typedef struct DLinkListNode
{
    struct DLinkListNode *next;
    struct DLinkListNode *pre;
}DLLNode;

DLinkList* DLinkList_Create();

void DLinkList_Destory(DLinkList *list);

void DLinkList_Clear(DLinkList *list);

int DLinkList_Length(DLinkList *list);

int DLinkList_Insert(DLinkList *list, DLLNode *node, int pos);

DLLNode* DLinkList_Get(DLinkList *list, int pos);

DLLNode* DLinkList_Delete(DLinkList *list,int pos);

//游标功能

DLLNode* DLinkList_DeleteNode(DLinkList *list,DLLNode *node);

DLLNode* DLinkList_Reset(DLinkList *list);

DLLNode* DLinkList_Next(DLinkList *list);

DLLNode* DLinkList_Pre(DLinkList *list);

DLLNode* DLinkList_Current(DLinkList *list);
