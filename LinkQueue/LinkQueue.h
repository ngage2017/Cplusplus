#pragma once

#ifndef _NG_LINKQUEUE_
#define _NG_LINKQUEUE_

typedef void Queue;

Queue *LinkQueue_Create();

void LinkQueue_Destory(Queue* queue);

void LinkQueue_Clear(Queue* queue);

int LinkQueue_Append(Queue* queue,void* item);

void* LinkQueue_Retrieve(Queue* queue);

void* LinkQueue_Header(Queue* queue);

int LinkQueue_Length(Queue* queue);

#endif
