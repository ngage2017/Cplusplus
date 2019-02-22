#pragma once

#ifndef _NG_LINKSTACK_
#define _NG_LINKSTACK_

typedef void LinkStack;

LinkStack* LinkStack_Create();

void LinkStack_Destory(LinkStack* stack);

void LinkStack_Clear(LinkStack* stack);

int LinkStack_Push(LinkStack* stack,void* item);

void* LinkStack_Top(LinkStack* stack);

void* LinkStack_Pop(LinkStack *stack);

int LinkStack_Size(LinkStack* stack);


#endif
