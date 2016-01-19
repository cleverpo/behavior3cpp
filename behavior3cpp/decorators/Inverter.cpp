//
//  Inverter.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "Inverter.hpp"

NS_B3_BEGIN

Inverter::Inverter(){
    m_name = "Inverter";
}

Inverter::Inverter(Value* properties){
    m_name = "Inverter";
}

Inverter::~Inverter(){
    
}

State Inverter::tick(Tick* tick){
    if(!this->m_child)
        return State::ERROR;
    
    State status = this->m_child->_execute(tick);
    
    if(status == State::SUCCESS)
        status = State::FAILURE;
    else if(status == State::FAILURE)
        status = State::SUCCESS;
    
    return status;
}

NS_B3_END