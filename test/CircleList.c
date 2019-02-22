#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleList.h"

typedef struct tag_CircleList
{
    CListNode header;
    CListNode *slider;
    int length;
}TCircleList;


CircleList* CircleList_Create()
{
    TCircleList *clist =NULL;

    clist = (TCircleList *)malloc(sizeof(TCircleList));

    memset(clist,0,sizeof(TCircleList*));
	return clist;
}

void CircleList_Destory(CircleList *list)
{
    if(list != NULL)
    {
        free(list);
        list = NULL;
    }
	return;
}

void CircleList_Clear(CircleList *list)
{
    TCircleList *clist = (TCircleList *)list;
    if(clist != NULL)
    {
        clist->length = 0;
        clist->slider = NULL;
        clist->header.next = NULL;
    }
	return;
}

int CircleList_Length(CircleList *list)
{
    int ret = 0;
    TCircleList *clist = (TCircleList *)list;
    
    if(clist != NULL)
    {
        ret = clist->length;
    }

	return ret;
}

CListNode* CircleList_Get(CircleList *list,int pos)
{
	return NULL;
}

int CircleList_Insert(CircleList *list,CListNode *node,int pos)
{
    int i = 0;
    TCircleList *clist = (TCircleList *)list;
   
    if(clist != NULL)
    {
        CListNode *current = (CListNode *)clist;
        for(i = 0; i < pos && current->next != NULL; i++)
        {
            current = current->next;
        }

        //尾部和中间插入法：
        node->next = current->next;
        current->next = node;
        
        //如果是插入的第一个节点，将游标移动到新插入的节点
        if(clist->length == 0)
        {
            clist->slider = node;
        }
        clist->length++;

        //如果是头部插入法
        if(current == (CListNode *)clist)
        {
            CListNode* last = CircleList_Get(clist,clist->length - 1);
            last->next = current->next;
        }
    }
	return 0;
}

CListNode *CircleList_Delete(CircleList *list,int pos)
{
    int i = 0;
    TCircleList *clist = (TCircleList *)list;
    CListNode* temp = NULL;
    CListNode* last = NULL;
    if(clist != NULL)
    {
        CListNode* current = (CListNode* )clist;    
        for(i = 0; i < pos && current->next != NULL;i++)
        {
            current = current->next;
        }

        //如果是中间删除或是尾部删除
        temp = current->next;
        current->next = temp->next;

        clist->length--;
        //如果是头部删除
        if(current == (CListNode *)clist)
        {
            last = CircleList_Get(clist,clist->length - 1);
        }

        //判断删除后链表是否为空
        
        if(last != NULL)
        {
            clist->header.next = temp->next;
            last->next = temp->next;
        }

        //如果删除的节点是游标指向的节点
        if(clist->slider == temp)
        {
            clist->slider = temp->next;
        }

        //如果删除节点后，链表长度为0
        
        if(clist->length == 0)
        {
            clist->header.next = NULL;
            clist->slider = NULL;
        }
    }
	return temp;
}

//游标功能

CListNode* CircleList_DeleteNode(CircleList *list,CListNode *node)
{
	return NULL;
}

CListNode* CircleList_Current(CircleList* list)
{
	return NULL;
}

CListNode* CircleList_Pre(CircleList *list)
{
	return NULL;
}

CListNode* CircleList_Reset(CircleList *list)
{
	return NULL;
}
