//
//  Factory.hpp
//  FactoryPattern
//
//  Created by ChenJun on 19/2/22.
//  Copyright © 2019年 ChenJun. All rights reserved.
//

#ifndef Factory_hpp
#define Factory_hpp

#include <stdio.h>
#include "Furit.hpp"

class Factory
{
public:
    Furit* getFurit(char* name);
};

#endif /* Factory_hpp */
