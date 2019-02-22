//
//  Singelton.cpp
//  Singelton
//
//  Created by ChenJun on 19/2/17.
//  Copyright © 2019年 ChenJun. All rights reserved.
//

#include "Singelton.hpp"
#include <iostream>
#include <unistd.h>

pthread_mutex_t mmutex = PTHREAD_MUTEX_INITIALIZER;
Singelton* Singelton::singel = NULL;
int Singelton::num = 0;

Singelton::Singelton()
{
    num++;
    printf("Singelton begin\n");
    sleep(10);
    printf("Singelton end\n");
}

Singelton* Singelton::getInstance()
{
    if(singel == NULL)
    {
        pthread_mutex_lock(&mmutex);
        if(singel == NULL)
        {
            singel = new Singelton;
        }
        pthread_mutex_unlock(&mmutex);
    }
    return singel;
}

void Singelton::prints()
{
    printf("num:%d\n",num);
}

