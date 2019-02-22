#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"
#include "LinkList.h"

typedef struct LinkStackNode
{
    LLNode node;
    void* item;
}LinkStackNode;

LinkStack* LinkStack_Create()
{
    return LinkList_Create();
}



void LinkStack_Destory(LinkStack* stack)
{
    LinkStack_Clear(stack);
    LinkList_Destory(stack);
	return ;
}

//清空一个栈相当于清空一个线性表
//所有入栈的元素都是malloc;
//如果要清空栈，把栈中的元素弹出，并且释放内存
void LinkStack_Clear(LinkStack* stack)
{
    if(stack == NULL)
    {
        return;
    }

    while(LinkStack_Size(stack) > 0)
    {
        LinkStack_Pop(stack);
    }
	return ;
}

//向栈中压入元素，相当于向线性表的头部插入元素
//void *item栈的业务节点====》转化成链表的业务节点node
int LinkStack_Push(LinkStack* stack,void* item)
{
    LinkStackNode * lsnode = NULL;
    int ret = 0;
    lsnode = (LinkStackNode *)malloc(sizeof(LinkStackNode));

    if(lsnode == NULL)
    {
        ret =-1;
        return ret;
    }

    memset(lsnode,0,sizeof(LinkStackNode));
    lsnode->item= item;
    ret = LinkList_Insert(stack,(LLNode *)lsnode,0);

    if(ret != 0)
    {
        ret = -2;
        printf("func LinkList_Insert() err:%d\n",ret);
        
        if(lsnode != NULL)
        {
            free(lsnode);
        }
        return ret;
    }
    return ret;
}

//获取栈的顶部元素，相当于获取链表的头部元素
void* LinkStack_Top(LinkStack* stack)
{
    LinkStackNode *temp = NULL;
    temp = (LinkStackNode *)LinkList_Get(stack,0);
    if(temp == NULL)
    {
        return NULL;
    }
	return temp->item;
}

//从栈中弹出元素，相当于从线性表的头部删除元素
//把线性表的业务节点转化成栈的业务节点
void* LinkStack_Pop(LinkStack *stack)
{
    void* item = NULL;//栈的业务节点
    LinkStackNode *temp = NULL;
    temp = (LinkStackNode *)LinkList_Delete(stack,0);
    if(temp == NULL)
    {
        return NULL;
    }

    item = temp->item;
    //因为LinkList_Insert的时候分配了内存，所以LinkList_Delete要释放内存
    free(temp);
    return item;
}

int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}
