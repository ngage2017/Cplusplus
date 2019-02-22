#include <stdio.h>
#include <stdlib.h>
#include "CircleList.h"

typedef struct tag_CircleList
{
    CListNode header;
    CListNode* slider;
    int length;
}TCircleList;

CircleList* CircleList_Create()
{
    TCircleList *list = NULL;

    list =(TCircleList *) malloc(sizeof(TCircleList));

    if(list == NULL)
    {
        return NULL;
    }

    list->length = 0;
    list->header.next = NULL;
    list->slider = NULL;
	return list;
}

void CircleList_Destory(CircleList* list)
{
    if(list != NULL)
    {
        free(list);
        list = NULL;
    }
	return;
}

void CircleList_Clear(CircleList* list)
{
    TCircleList *clist = NULL;
    if(list == NULL)
    {
        return;
    }

    clist = (TCircleList *)list;

    clist->length = 0;
    clist->header.next = NULL;
    clist->slider = NULL;
	return;
}

int CircleList_Length(CircleList* list)
{
    int ret = 0;
    TCircleList *clist = NULL;
    if(list == NULL)
    {
        ret = -1;
        return ret;
    }

    clist = (TCircleList *)list;
	return clist->length;
}

int CircleList_Insert(CircleList* list,CListNode *node,int pos)
{
    int ret = 0,i = 0;
    TCircleList *clist = NULL;
    CListNode *current = NULL;
        
    if(list == NULL || node == NULL || pos < 0)
    {
        ret = -2;
        return ret;
    }

    clist = (TCircleList *)list;
    //辅助指针变量指向链表头部
    current = (CListNode *)clist;
    for(i = 0; i < pos && (current->next != NULL); i++)
    {
        current = current->next;
    }

    node->next = current->next;
    current->next = node;


    if(clist->length == 0)
    {
        clist->slider = node;
    }
    clist->length++;
    
    if(current ==(CListNode *) clist)
    {
        CListNode* last = CircleList_Get(clist,clist->length -1);
        last->next = current->next;
    }

	return ret;
}

CListNode* CircleList_Get(CircleList* list, int pos)
{
    int i = 0;
    CListNode *current = NULL;
    TCircleList *clist = NULL;
    if(list == NULL || pos < 0)
    {
        return NULL;
    }

    clist =(TCircleList *) list;

    current = &(clist->header);
    for(i = 0 ; i < pos; i++)
    {
        current = current->next;
    }

	return current->next;
}

CListNode* CircleList_Delete(CircleList* list,int pos)
{
    int i = 0;
    TCircleList *clist =(TCircleList *) list;
    CListNode *temp = NULL;

    if(clist != NULL &&  pos >= 0 && clist->length > 0)
    {
    

    CListNode *current = (CListNode *)clist;
    CListNode *last = NULL;
    for(i = 0; i < pos ;i++)
    {
        current = current->next;
    }


    //如果删除头部节点
    if(current == (CListNode *)clist)
    {
        last = (CListNode *)CircleList_Get(clist,clist->length - 1);
    }
    temp = current->next;
    current->next = temp->next;

    clist->length--;

    //判断链表是否为空
    if(last != NULL)
    {
        clist->header.next = temp->next;
        last->next = temp->next;
    }
    
    //若删除的节点为游标所指的节点
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
        
    }else
    {
        return NULL;
    }
	return temp;
}

//游标功能

CListNode* CircleList_DeleteNode(CircleList* list,CListNode* node)
{
    int i = 0;
    TCircleList *clist = (TCircleList *)list;
    CListNode *temp = NULL;

    if(clist != NULL)
    {
        CListNode *current = (CListNode *)clist;

        //查找node在循环链表中的位置i
        
        for(i = 0 ; i < clist->length;i++)
        {
            if(current->next == node)
            {
                temp = current->next;
                break;
            }
            current = current->next;
        }

        //如果找到temp，根据I去删除
        if(temp != NULL)
        {
            CircleList_Delete(clist,i);
        }
    }
	return temp;
}

CListNode* CircleList_Reset(CircleList *list)
{
    TCircleList *clist = (TCircleList *)list;
    CListNode *temp = NULL;

    if(clist != NULL)
    {
        clist->slider = clist->header.next;
        temp = clist->slider;
    }
    return temp;
}

CListNode* CircleList_Current(CircleList* list)
{
    TCircleList *clist = (TCircleList *)list;
    CListNode *temp = NULL;

    if(clist != NULL)
    {
        temp = clist->slider;
    }
	return temp;
}

CListNode* CircleList_Next(CircleList* list)
{
    TCircleList *clist = (TCircleList *)list;
    CListNode *temp = NULL;

    if(clist != NULL && clist->slider != NULL)
    {
        temp = clist->slider;
        clist->slider = temp->next;
    }
    return temp;
}
