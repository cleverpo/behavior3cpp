//
//  Error.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "Error.hpp"

NS_B3_BEGIN

Error::Error(){
    m_name = "Error";
}

Error::Error(Value* properties){
    m_name = "Error";
}

Error::~Error(){

}

State Error::tick(Tick* tick){
    return State::ERROR;
}

NS_B3_END