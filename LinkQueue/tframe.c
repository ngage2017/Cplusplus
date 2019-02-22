#include <stdio.h>
#include "LinkQueue.h"

typedef struct Teacher
{
    int age;
}Teacher;

int main()
{
    Teacher t1,t2,t3,*temp;
    Queue *queue = LinkQueue_Create();

    t1.age = 11;
    t2.age = 12;
    t3.age = 13;
    if(queue == NULL)
    {
        printf("Queue is NULL\n");
        return 0;
    }

    LinkQueue_Append(queue,(void *)&t1);

    LinkQueue_Append(queue,(void *)&t2);

    LinkQueue_Append(queue,(void *)&t3);

    //队列属性操作
    //
    printf("Len = %d\n",LinkQueue_Length(queue));
    
    temp =(Teacher *) (long)LinkQueue_Header(queue);
    printf("=====>%d\n",temp->age);
    //出队列操作
    while(LinkQueue_Length(queue) > 0)
    {
        temp = (Teacher*)(long)LinkQueue_Retrieve(queue);
        printf("temp->age:%d\n",temp->age);
    }

    LinkQueue_Clear(queue);

    LinkQueue_Destory(queue);
    printf("Hello world\n");
    return 0;
}

