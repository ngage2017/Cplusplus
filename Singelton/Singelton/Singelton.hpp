//
//  Singelton.hpp
//  Singelton
//
//  Created by ChenJun on 19/2/17.
//  Copyright © 2019年 ChenJun. All rights reserved.
//
#pragma once
#ifndef Singelton_hpp
#define Singelton_hpp

class Singelton
{
private:
    Singelton();
    static Singelton* singel;
    static int num;
public:
    static Singelton* getInstance();
    static void prints();
};

#endif /* Singelton_hpp */
