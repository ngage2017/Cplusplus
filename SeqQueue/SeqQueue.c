#include <stdio.h>
#include "SeqQueue.h"
#include "SeqList.h"

//队列也是一种特殊的线性表


//创建一个队列，相当于创建一个线性表
Queue* SeqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}

//销毁一个队列，相当于销毁一个线性表
void SeqQueue_Destory(Queue* queue)
{
	 SeqList_Destory(queue);
}

void SeqQueue_Clear(Queue* queue)
{
	 SeqList_Clear(queue);
}

//向队列中加元素，相当于向线性表中插入元素
int SeqQueue_Append(Queue* queue,void *item)
{
	return SeqList_Insert(queue,item,SeqList_Length(queue));
}

//出队列，相当于从线性表中删除0号元素
void* SeqQueue_Retrieve(Queue* queue)
{
	return SeqList_Delete(queue,0);
}

void* SeqQueue_Header(Queue* queue)
{
	return SeqList_Get(queue,0);
}

int SeqQueue_Length(Queue* queue)
{
	return SeqList_Length(queue);
}

int SeqQueue_Capacity(Queue* queue)
{
    return SeqList_Capacity(queue);
}
