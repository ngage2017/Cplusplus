#include <stdio.h>
#include "SeqQueue.h"

int main()
{
    int i = 0;
    int array[5];

    Queue* queue = NULL;

    queue = SeqQueue_Create(10);
    
    if(queue ==NULL)
    {
        return ;
    }
    for(i = 0 ; i < 5; i++)
    {
        array[i] = i + 10;
        SeqQueue_Append(queue,&array[i]);
    }

    //打印队列的属性
    
    printf("queue len:%d\n",SeqQueue_Length(queue));
    printf("queue header:%d\n",*((int *)SeqQueue_Header(queue)));
    printf("queue capacity:%d\n",SeqQueue_Capacity(queue));

    //删除队列
    while(SeqQueue_Length(queue) > 0)
    {
        int temp = *((int*)SeqQueue_Retrieve(queue));
        printf("temp:%d\n",temp);
    }

    SeqQueue_Destory(queue);

    printf("Hello world\n");
    return 0;
}

