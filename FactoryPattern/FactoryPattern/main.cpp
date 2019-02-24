//
//  main.cpp
//  FactoryPattern
//
//  Created by ChenJun on 19/2/22.
//  Copyright © 2019年 ChenJun. All rights reserved.
//

#include <iostream>
#include <string>
#include "Factory.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    Factory *ft = new Factory;
    Furit *furit = NULL;
    char ftname[] = "apple";
    char ftname1[] = "banan";
    
    furit = ft->getFurit(ftname);
    furit->sayName();
    delete ft;
    delete furit;
    
    
    furit = ft->getFurit(ftname1);
    furit->sayName();
    return 0;
}
