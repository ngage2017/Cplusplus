//
//  Banan.hpp
//  FactoryPattern
//
//  Created by ChenJun on 19/2/22.
//  Copyright © 2019年 ChenJun. All rights reserved.
//

#pragma once
#ifndef Banan_hpp
#define Banan_hpp
#include "Furit.hpp"

class Banan:public Furit
{
public:
    virtual void sayName(void);
};

#endif /* Banan_hpp */
