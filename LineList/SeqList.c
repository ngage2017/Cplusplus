#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqList.h"


typedef struct tag_SeqList
{
    int length;
    int capacity;
    unsigned int **node;
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
    TSeqList *tlist = NULL;
    tlist = (TSeqList *)malloc(sizeof(TSeqList));
    if(tlist == NULL)
    {
        return NULL;
    }

    memset(tlist,0,sizeof(TSeqList));
    tlist->node =(unsigned int **) malloc(sizeof(unsigned int*)*capacity);
    tlist->length = 0;
    tlist->capacity = capacity;
   
    return tlist;
}

void SeqList_Destory(SeqList *list)
{
    TSeqList *tlist = NULL;
    if(list == NULL)
    {
        return ;
    }

    tlist = (TSeqList *)list;

    if(tlist->node != NULL)
    {
        free(tlist->node);
    }
    free(tlist);
    return;
}

void SeqList_Clear(SeqList *list)
{
    TSeqList *tlist = NULL;
    if(list == NULL)
    {
        return;
    }

    tlist = (TSeqList *)list;

    tlist->length = 0;
    return ;
}

int SeqList_Length(SeqList *list)
{
    int ret = 0;
    TSeqList *tlist = NULL;
    if(list == NULL)
    {
        ret = -1;
        return ret;
    }

    tlist = (TSeqList *)list;


    return tlist->length;
}

int SeqList_Capacity(SeqList *list)
{
    int ret = 0;
    TSeqList *tlist = NULL;
    if(list == NULL)
    {
        ret = -1;
        return ret;
    }

    tlist = (TSeqList *)list;
    return tlist->capacity;
}

int SeqList_Insert(SeqList* list,SeqListNode *node, int pos)
{
    TSeqList *tlist = NULL;
    int i = 0,ret = 0;
    if(list == NULL || node == NULL || pos < 0)
    {
        ret = -1;
        return ret;
    }

    
    tlist = (TSeqList *)list;

    if(tlist->length >= tlist->capacity)
    {
        ret = -2;
        printf("The cantier is Full!\n");
        return ret;
    }
    
    if(pos >= tlist->length)
    {
        pos = tlist->length;
    }

    for(i = tlist->length; i > pos; i--)
    {
        tlist->node[i]=tlist->node[i-1];
    }

    tlist->node[i] = node;
    tlist->length++;
    return ret;
}

SeqListNode* SeqList_Delete(SeqList *list, int pos)
{
    int i = 0;
    SeqListNode *temp = NULL;
    TSeqList *tlist = NULL;
    if(list == NULL || pos < 0)
    {
        return NULL;
    }

    tlist = (TSeqList *)list;

    temp =(SeqListNode *) tlist->node[pos];

    for(i = pos+1 ; i < tlist->length;i++)
    {
        tlist->node[i - 1]= tlist->node[i];
    }
    tlist->length--;
    return temp;
}

SeqListNode* SeqList_Get(SeqList* list,int pos)
{
    SeqListNode *temp = NULL;
    TSeqList *tlist = NULL;
    if(list == NULL || pos < 0)
    {
        return NULL;
    }

    tlist = (TSeqList *)list;
    temp =(SeqListNode *) tlist->node[pos];
    return temp;
}


