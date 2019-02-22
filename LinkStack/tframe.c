#include <stdio.h>
#include "LinkStack.h"

int main()
{
    int i = 0;
    int array[10];

    LinkStack *stack = NULL;
    stack = LinkStack_Create();

    //向链式栈中压入元素
    for(i = 0; i < 5; i++)
    {
        array[i] = i + 10;
        LinkStack_Push(stack,&array[i]);
    }

    //获取链式栈的属性
    printf("Size:%d\n",LinkStack_Size(stack));
    printf("Top:%d\n",*((int *)LinkStack_Top(stack)));

    while(LinkStack_Size(stack) > 0)
    {
     printf("Pop:%d\n",*((int *)LinkStack_Pop(stack)));
    }

    return 0;
}

