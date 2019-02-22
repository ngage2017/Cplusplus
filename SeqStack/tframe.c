#include <stdio.h>
#include "SeqStack.h"

int main()
{
    int i = 0;
    int array[10];
    SeqStack* stack = NULL;

    stack= SeqStack_Create(10);

    if(stack == NULL)
    {
        return ;
    }

    for(i = 0; i < 5; i++)
    {
        array[i] = i + 10;
        SeqStack_Push(stack,&array[i]);
    }

    printf("Capacity:%d\n",SeqStack_Capacity(stack));

    printf("Size:%d\n",SeqStack_Size(stack));

    printf("Top:%d\n",*((int *)SeqStack_Top(stack)));

    while(SeqStack_Size(stack) > 0)
    {
        int temp =*( (int *)SeqStack_Pop(stack) );
        printf("temp:%d\n",temp);
    }

    /*SeqStack* SeqStack_Create(int capacity);

    void SeqStack_Destory(SeqStack* stack);

    void SeqStack_Clear(SeqStack* stack);

    int SeqStack_Push(SeqStack* stack,void* item);

    void* SeqStack_Pop(SeqStack* stack);

    void* SeqStack_Top(SeqStack *stack);

    int SeqStack_Size(SeqStack* stack);

    int SeqStack_Capacity(SeqStack* stack);*/
    printf("Hello world\n");
    return 0;
}

