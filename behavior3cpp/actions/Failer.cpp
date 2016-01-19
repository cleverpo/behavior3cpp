//
//  Failer.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "Failer.hpp"

NS_B3_BEGIN

Failer::Failer(){
    m_name = "Failer";
}

Failer::Failer(Value* properties){
    m_name = "Failer";
}

Failer::~Failer(){

}

State Failer::tick(Tick* tick){
    return State::FAILURE;
}

NS_B3_END