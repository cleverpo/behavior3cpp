//
//  b3.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/4.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef b3_hpp
#define b3_hpp

#include <string>
#include <stdlib.h>
#include <math.h>
#include <random>

#define NS_B3_BEGIN namespace b3{
#define NS_B3_END }
#define USING_NS_B3 using namespace b3;

NS_B3_BEGIN

const std::string VERSTION = "0.1.0";
const std::string COMPOSITE = "composite";
const std::string DECORATOR = "decorator";
const std::string ACTION = "action";
const std::string CONDITION = "condition";

enum State{
    NONE = 0,
    SUCCESS = 1,
    FAILURE = 2,
    RUNNING = 3,
    ERROR = 4
};

std::string createUUID();

NS_B3_END

#endif /* b3_hpp */
