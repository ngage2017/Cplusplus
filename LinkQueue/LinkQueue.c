#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkQueue.h"
#include "LinkList.h"

//队列也是一种特殊的线性表
//尾进头出队列
//队列的业务节点的数据结构
typedef struct LQNode
{
    LLNode* node;
    void* item;
}LQNode;
//创建链式队列，相当于创建一个链式线性表
Queue *LinkQueue_Create()
{ 
	return LinkList_Create();
}

//销毁队列，相当于销毁线性表
//涉及到业务节点的内存管理
void LinkQueue_Destory(Queue* queue)
{
    LinkQueue_Clear(queue);
    LinkList_Destory(queue);
	return ;
}


void LinkQueue_Clear(Queue* queue)
{
    if(queue == NULL)
    {
        return;
    }
    while(LinkQueue_Length(queue) > 0)
    {
        LinkQueue_Retrieve(queue);
    }
	return;
}

//向队列添加元素，相当于向线性表的尾部添加元素
int LinkQueue_Append(Queue* queue,void* item)
{
    int ret = 0;
    LQNode* lqueue = NULL;
    lqueue = (LQNode*)malloc(sizeof(LQNode));
    if(lqueue == NULL)
    {
        ret = -1;
        printf("func LinkQueue_Append() err:%d\n",ret);
        return ret;
    }

    memset(lqueue,0,sizeof(LQNode));
    lqueue->item = item;
    //需要把队列的 item(队列的业务节点)转化成链表的LLNode
    ret = LinkList_Insert(queue,(LLNode*) lqueue,LinkList_Length(queue));
    if(ret != 0)
    {
        printf("func LinkList_Insert() err:%d\n",ret);
        return ret;
    }
	return ret;
}

//出队列，相当于从线性表的头部删除元素
void* LinkQueue_Retrieve(Queue* queue)
{
    LQNode *temp = NULL;
    void* ret =NULL;
    temp = (LQNode *)LinkList_Delete(queue,0);

    if(temp == NULL)
    {
        printf("func LinkList_Delete() err\n");
        return NULL;
    }

    ret = temp->item;
    if(temp != NULL)
    {
        free(temp);
    }
	return ret;
}

//获取队列头部元素，相当于获取线性表0号位置元素
void* LinkQueue_Header(Queue* queue)
{
    LQNode* ret = NULL;
    ret = (LQNode*)LinkList_Get(queue,0);
    if(ret == NULL)
    {
        printf("func LinkList_Get() err\n");
        return NULL;
    }
	return ret->item;
}

int LinkQueue_Length(Queue* queue)
{
	return LinkList_Length(queue);
}

