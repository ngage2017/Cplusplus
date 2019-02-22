#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"


typedef struct tag_LinkList
{
    LLNode header;
    int length;
}TLinkList;

LinkList* LinkList_Create()
{
    TLinkList *list = NULL;

    list =(TLinkList *) malloc(sizeof(TLinkList));
    if(list == NULL)
    {
        return NULL;
    }

    memset(list,0,sizeof(TLinkList));
    list->header.next = NULL;
    list->length = 0;
    return list;
}

void LinkList_Destory(LinkList *list)
{
    if(list != NULL)
    {
        free(list);
        list = NULL;
    }
    return;
}

void LinkList_Clear(LinkList *list)
{
    TLinkList *tlist = NULL;
    if(list == NULL)
    {
        return;
    }

    tlist = (TLinkList *)list;

    tlist->length = 0;
    tlist->header.next = NULL;
    return;
}

int LinkList_Length(LinkList* list)
{
    int ret = 0;
    TLinkList *tlist = NULL;

    if(list == NULL)
    {
        ret = -1;
        return ret;
    }

    tlist = (TLinkList *)list;

    return tlist->length;
}

int LinkList_Insert(LinkList* list,LLNode* node,int pos)
{
    int ret = 0,i = 0;
    LLNode *current = NULL;
    TLinkList *tlist = NULL;
    if(list == NULL || pos < 0 || node == NULL)
    {
        ret = -1;
        return ret;
    }
    tlist = (TLinkList *)list;
    current = &(tlist->header);
   
    for(i = 0; i < pos && (current->next != NULL);i++)
    {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;

    tlist->length++;
    return ret;
}

LLNode* LinkList_Delete(LinkList* list, int pos)
{
    int i = 0;
    LLNode *temp = NULL,*current = NULL;
    TLinkList *tlist = NULL;
    if(list == NULL || pos < 0)
    {
        return NULL;
    }
    tlist = (TLinkList *)list;
    current =& (tlist->header);

    for(i = 0; i < pos; i++)
    {
        current = current->next;
    }

    temp = current->next;
    current->next = temp->next;
    tlist->length--;
    return temp;
}

LLNode* LinkList_Get(LinkList* list,int pos)
{
    int i = 0;
    TLinkList *tlist = NULL;
    LLNode *temp = NULL;

    if(list == NULL || pos < 0)
    {
        return NULL;
    }
    tlist = (TLinkList *)list;

    temp = &(tlist->header);
    for(i = 0; i < pos && (temp->next != NULL) ; i++)
    {
        temp = temp->next;
    }
    return temp->next;
}
