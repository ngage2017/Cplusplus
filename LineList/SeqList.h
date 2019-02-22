#pragma once

typedef void SeqList;
typedef void SeqListNode;

SeqList* SeqList_Create(int capacity);

void SeqList_Destory(SeqList *list);

void SeqList_Clear(SeqList *list);

int SeqList_Length(SeqList *list);

int SeqList_Capacity(SeqList *list);

SeqListNode* SeqList_Delete(SeqList* list, int pos);

SeqListNode* SeqList_Get(SeqList* list,int pos);

int SeqList_Insert(SeqList *list, SeqListNode *node, int pos);

