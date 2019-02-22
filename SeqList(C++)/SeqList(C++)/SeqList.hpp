//
//  SeqList.hpp
//  SeqList(C++)
//
//  Created by ChenJun on 19/2/20.
//  Copyright © 2019年 ChenJun. All rights reserved.
//
#pragma once
#ifndef SeqList_hpp
#define SeqList_hpp


template <typename T>

class SeqList
{
 public:
    SeqList(int capacity);
    ~SeqList(void);

    int Clear();
    int Length();
    int Capacity();
    int Delete(int pos,T &t);
    int Get(int pos,T &t);
    int Insert(T &t, int pos);
    
 private:
    int length;
    int capacity;
    T *pArray;
};


#endif /* SeqList_hpp */
