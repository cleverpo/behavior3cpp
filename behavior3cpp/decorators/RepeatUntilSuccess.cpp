//
//  RepeatUnitlSuccess.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "RepeatUntilSuccess.hpp"
#include "core/Tick.hpp"
#include "core/BehaviorTree.hpp"

NS_B3_BEGIN

RepeatUntilSuccess::RepeatUntilSuccess():
m_maxLoop(-1)
{
    m_name = "RepeatUntilSuccess";
}

RepeatUntilSuccess::RepeatUntilSuccess(Value* properties):
m_maxLoop(-1)
{
    m_name = "RepeatUntilSuccess";
    m_maxLoop = properties->asMap()["maxLoop"].asInt();
}

RepeatUntilSuccess::~RepeatUntilSuccess(){
}

void RepeatUntilSuccess::open(Tick* tick){
    tick->getBlackBoard()->set("i", Value(0), tick->getTree()->getId(), this->getId());
}

State RepeatUntilSuccess::tick(Tick* tick){
    if(!this->m_child)
        return State::ERROR;
    
    State status = State::SUCCESS;
    int i = tick->getBlackBoard()->get("i", tick->getTree()->getId(), this->getId()).asInt();
    
    while(m_maxLoop < 0 || i < m_maxLoop){
        status = m_child->_execute(tick);
        
        if(status == State::FAILURE)
            i++;
        else
            break;
    }
    
    tick->getBlackBoard()->set("i", Value(i), tick->getTree()->getId(), this->getId());
    
    return status;
}

NS_B3_END