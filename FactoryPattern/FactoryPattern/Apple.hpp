//
//  Apple.hpp
//  FactoryPattern
//
//  Created by ChenJun on 19/2/22.
//  Copyright © 2019年 ChenJun. All rights reserved.
//
#pragma once
#ifndef Apple_hpp
#define Apple_hpp

#include "Furit.hpp"

class Apple:public Furit
{
public:
    virtual void sayName(void);
};

#endif /* Apple_hpp */
