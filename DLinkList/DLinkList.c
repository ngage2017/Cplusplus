#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkList.h"

typedef struct tag_DLinkList
{
    DLLNode header;
    DLLNode* slider;
    int length;
}tDLinkList;


DLinkList* DLinkList_Create()
{
    tDLinkList *dlist = NULL;
    dlist = (tDLinkList*)malloc(sizeof(tDLinkList ));

    memset(dlist,0,sizeof(tDLinkList));
	return dlist;
}

void DLinkList_Destory(DLinkList *list)
{
    tDLinkList *dlist = (tDLinkList *)list;

    if(dlist != NULL)
    {
        free(dlist);
    }
	return ;
}

void DLinkList_Clear(DLinkList *list)
{
    tDLinkList *dlist = (tDLinkList *)list;

    if(dlist != NULL)
    {
        dlist->header.next = NULL;
        dlist->header.pre = NULL;
        dlist->slider = NULL;
        dlist->length = 0;
    }
	return ;
}

int DLinkList_Length(DLinkList *list)
{
    int ret = -1;

    tDLinkList *dlist = (tDLinkList *)list;

    if(dlist != NULL)
    {
        ret = dlist->length;  
    }
	return ret;
}

int DLinkList_Insert(DLinkList *list, DLLNode *node, int pos)
{
    int ret = 0, i = 0;
    tDLinkList *dlist = (tDLinkList *)list;
    DLLNode* current =NULL;

    if(list == NULL || pos < 0 || node == NULL)
    {
        ret = -1;
        return ret;
    }

    if(dlist != NULL)
    {
        DLLNode* next = NULL;
        current = (DLLNode *)dlist;
        for(i = 0; i < pos; i++)
        {
            current = current->next;
        }

        next = current->next;
        current->next = node;
        node->next = next;
        
        
        //如果是插入的第一个节点
        if(next != NULL)
        {
            next->pre = node;
        }

        node->pre = current;

        if(dlist->length == 0)
        {
            dlist->slider = node;//当链表插入第一个节点处理游标；
        }

        //如果在0位置插入，需要将给新节点前驱pre指向NULL；
        if(current = (DLLNode *)dlist)
        {
            node->pre = NULL;
        }

        dlist->length++;
    }
	return ret;
}

DLLNode* DLinkList_Get(DLinkList *list, int pos)
{
    int i = 0;
    DLLNode* temp = NULL;
    tDLinkList* dlist = (tDLinkList*)list;
    if(dlist != NULL)
    {
        DLLNode* current = (DLLNode *)dlist;
        for(i = 0; i < pos; i++)
        {
            current = current->next;
        }
        
        temp = current->next;
    }
	return temp;
}

DLLNode* DLinkList_Delete(DLinkList *list,int pos)
{
    int i = 0;
    tDLinkList* dlist = (tDLinkList *)list;
    DLLNode* temp = NULL;
    if(dlist != NULL)
    {
        DLLNode* next = NULL;
        DLLNode *current = (DLLNode *)dlist;
        for(i = 0 ; i < pos; i++)
        {
            current = current->next;
        }
        temp = current->next;
        next = temp->next;
        current->next = next;

        if(next!= NULL)
        {
            next->pre = current;
            if(current ==(DLLNode *) dlist)
            {
                next->pre = NULL;
            }
        }

        if(dlist->slider == temp)
        {
            dlist->slider = next;
        }

        dlist->length--;

        if(dlist->length == 0)
        {
            dlist->header.next= NULL;
            dlist->header.pre = NULL;
            dlist->slider = NULL;
        }
    }
	return temp;
}

//游标功能

DLLNode* DLinkList_DeleteNode(DLinkList *list,DLLNode *node)
{
    int i = 0;
    DLLNode * temp = NULL;
    tDLinkList *dlist =(tDLinkList *) list;
    if(dlist != NULL)
    {
        DLLNode *current = (DLLNode *)dlist;
       
        for(i = 0; i < dlist->length;i++)
        {
            if(current->next == node)
            {
                temp = current->next;
                break;
            }
            current = current->next;
        }

        if(temp != NULL)
        {
            DLinkList_Delete(dlist,i);
        }
    }
	return temp;
}

DLLNode* DLinkList_Reset(DLinkList *list)
{
    DLLNode* temp = NULL;
    tDLinkList* dlist = (tDLinkList *)list;
    if(dlist != NULL)
    {
        dlist->slider = dlist->header.next;
        temp = dlist->slider;
    }
	return temp;
}

DLLNode* DLinkList_Next(DLinkList *list)
{
    tDLinkList* dlist = (tDLinkList *)list;
	DLLNode* temp = NULL;

    if(dlist != NULL && dlist->slider != NULL)
    {
        temp = dlist->slider;
        dlist->slider = temp->next;
    }
    return temp;
}

DLLNode* DLinkList_Pre(DLinkList *list)
{
    tDLinkList* dlist = (tDLinkList *)list;
    DLLNode* temp = NULL;

    if(dlist != NULL)
    {
        temp = dlist->slider;
        dlist->slider = temp->pre;
    }
	return temp;
}

DLLNode* DLinkList_Current(DLinkList *list)
{
    tDLinkList * dlist = (tDLinkList *)list;
    DLLNode* temp = NULL;

    if(dlist != NULL)
    {
        temp = dlist->slider;
    }
	return temp;
}
