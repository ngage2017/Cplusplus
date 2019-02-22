//
//  SeqList.cpp
//  SeqList(C++)
//
//  Created by ChenJun on 19/2/20.
//  Copyright © 2019年 ChenJun. All rights reserved.
//
#include <iostream>
#include "SeqList.hpp"   

template <typename T>
SeqList<T>::SeqList(int capacity)
{
    //pArray = new char[10];
    pArray = new T[capacity];
    this->length = 0;
    this->capacity = capacity;
}

template <typename T>
SeqList<T>::~SeqList(void)
{
    delete[] pArray;
    pArray = NULL;
    length = 0;
    capacity = 0;
    std::cout<<"SeqList has been Destoried\n";
}

template <typename T>
int SeqList<T>::Clear()
{
    this->length = 0;
    return 0;
}

template <typename T>
int SeqList<T>::Capacity()
{
    return this->capacity;
}

template <typename T>
int SeqList<T>::Length()
{
    return this->length;
}

template <typename T>
int SeqList<T>::Delete(int pos,T &t)
{
    int i = 0;
    t = pArray[pos]; //缓存POS位置的节点
    
    for(i = pos +1; i < this->length;i++)
    {
        pArray[i - 1] = pArray[i];
    }
    length--;
    return 0;
}

template <typename T>
int SeqList<T>::Get(int pos,T &t)
{
    if(pos < 0)
    {
        return -1;
    }
    t = pArray[pos];
    return 0;
}

template <typename T>
int SeqList<T>::Insert(T &t, int pos)
{
    int i = 0;
    if(pos < 0)
    {
        return -1;
    }
    
    for(i = this->length; i > pos; i--)
    {
        pArray[i]=pArray[i-1];
    }
    pArray[i] = t;
    length++;
    return 0;
}
