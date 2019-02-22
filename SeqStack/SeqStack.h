#pragma once
#ifndef MY_SEQSTACK_
#define MY_SEQSTACK_


typedef void SeqStack;

SeqStack* SeqStack_Create(int capacity);

void SeqStack_Destory(SeqStack* stack);

void SeqStack_Clear(SeqStack* stack);

int SeqStack_Push(SeqStack* stack,void* item);

void* SeqStack_Pop(SeqStack* stack);

void* SeqStack_Top(SeqStack *stack);

int SeqStack_Size(SeqStack* stack);

int SeqStack_Capacity(SeqStack* stack);

#endif
