//
//  main.cpp
//  Singelton
//
//  Created by ChenJun on 19/2/17.
//  Copyright © 2019年 ChenJun. All rights reserved.
//


#include <iostream>
#include <pthread.h>
#include "Singelton.hpp"
#define NUM_THREADS 3

using namespace std;
pthread_t tids[NUM_THREADS];

void* threadfunc(void* args)
{
    pthread_t id = pthread_self();
    Singelton::getInstance()->prints();
    cout<<"thread id:"<<id<<endl;
    return NULL;
}

void* sayhello(void* args)
{
    cout<<"hello ngage\n";
    return NULL;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //Singelton *s = Singelton::getInstance();
    //Singelton *s1 = Singelton::getInstance();
    
    for(int i = 0; i < NUM_THREADS; i++)
    {
        int ret = pthread_create(&tids[i],NULL,threadfunc,NULL);
        
        if(ret != 0)
        {
            cout<<"pthread_Create err: "<< ret<<endl;
        }
    }
    /*for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tids[i],NULL);
    }*/
    pthread_exit(NULL);
    return 0;
}

