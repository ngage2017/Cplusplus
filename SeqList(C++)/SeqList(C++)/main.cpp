//
//  main.cpp
//  SeqList(C++)
//
//  Created by ChenJun on 19/2/19.
//  Copyright © 2019年 ChenJun. All rights reserved.
//

#include <iostream>
#include "SeqList.cpp"
using namespace std;

class teacher
{
public:
    int age;
    char name[64];
};


int main11(int argc, const char * argv[]) {
    // insert code here...
    teacher t1,t2,t3,t4;
    t1.age = 20;
    t2.age = 21;
    t3.age = 22;
    t4.age = 23;
    SeqList<teacher> list(5);//创建一个SeqList对象；
    list.Insert(t1,0);
    list.Insert(t2, 0);
    list.Insert(t3, 0);
    list.Insert(t4, 0);//插入元素，头插法
    
    //遍历线性表
    for(int i = 0; i < list.Length();i++)
    {
        teacher temp;
        list.Get(i, temp);
        cout<<"temp"<<i<<".age = "<<temp.age<<endl;
    }
    
    //清空线性表
    teacher temp;
    list.Delete(0, temp);
    return 0;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    teacher t1,t2,t3,t4;
    teacher *p1,*p2,*p3,*p4;
    t1.age = 20;
    t2.age = 21;
    t3.age = 22;
    t4.age = 23;
    
    p1 = &t1;
    p2 = &t2;
    p3 = &t3;
    p4 = &t4;
    
    SeqList<teacher*> list(5);//创建一个SeqList对象；
    list.Insert(p1,0);
    list.Insert(p2, 0);
    list.Insert(p3, 0);
    list.Insert(p4, 0);//插入元素，头插法
    
    //遍历线性表
    for(int i = 0; i < list.Length();i++)
    {
        teacher *temp;
        list.Get(i, temp);
        cout<<"temp"<<i<<".age = "<<temp->age<<endl;
    }
    
    //清空线性表
    teacher *temp;
    list.Delete(0, temp);
    return 0;
}
