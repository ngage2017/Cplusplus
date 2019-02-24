//
//  Factory.cpp
//  FactoryPattern
//
//  Created by ChenJun on 19/2/22.
//  Copyright © 2019年 ChenJun. All rights reserved.
//

#include <iostream>
#include "Factory.hpp"
#include "Apple.hpp"
#include "Banan.hpp"

Furit* Factory::getFurit(char * name)
{
    if(strcmp(name,"apple")==0)
    {
        return new Apple;
    }else if(strcmp(name,"banan")==0)
    {
        return new Banan;
    }
    else
    {
        return NULL;
    }
}
