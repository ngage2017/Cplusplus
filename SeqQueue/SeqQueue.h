#pragma once

#ifndef _NG_SEQQUEUE
#define _NG_SEQQUEUE

typedef void Queue;

Queue* SeqQueue_Create(int capacity);

void SeqQueue_Destory(Queue* queue);

void SeqQueue_Clear(Queue* queue);

int SeqQueue_Append(Queue* queue,void *item);

void* SeqQueue_Retrieve(Queue* queue);

void* SeqQueue_Header(Queue* queue);

int SeqQueue_Length(Queue* queue);

int Seqqueue_Capacity(Queue* queue);

#endif

