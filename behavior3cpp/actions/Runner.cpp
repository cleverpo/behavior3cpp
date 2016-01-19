//
//  Runner.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "Runner.hpp"

NS_B3_BEGIN

Runner::Runner(){
    m_name = "Runner";
}

Runner::Runner(Value* properties){
    m_name = "Runner";
}

Runner::~Runner(){

}

State Runner::tick(Tick* tick){
    return State::RUNNING;
}

NS_B3_END