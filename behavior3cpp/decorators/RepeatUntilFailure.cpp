//
//  RepeatUntilFailure.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "RepeatUntilFailure.hpp"
#include "core/Tick.hpp"
#include "core/BehaviorTree.hpp"

NS_B3_BEGIN

RepeatUntilFailure::RepeatUntilFailure():
m_maxLoop(-1)
{
    m_name = "RepeatUntilFailure";
}

RepeatUntilFailure::RepeatUntilFailure(Value* properties):
m_maxLoop(-1)
{
    m_name = "RepeatUntilFailure";
    m_maxLoop = properties->asMap()["maxLoop"].asInt();
}

RepeatUntilFailure::~RepeatUntilFailure(){
}

void RepeatUntilFailure::open(Tick* tick){
    tick->getBlackBoard()->set("i", Value(0), tick->getTree()->getId(), this->getId());
}

State RepeatUntilFailure::tick(Tick* tick){
    if(!this->m_child)
        return State::ERROR;
    
    State status = State::SUCCESS;
    int i = tick->getBlackBoard()->get("i", tick->getTree()->getId(), this->getId()).asInt();
    
    while(m_maxLoop < 0 || i < m_maxLoop){
        status = m_child->_execute(tick);
        
        if(status == State::SUCCESS)
            i++;
        else
            break;
    }
    
    tick->getBlackBoard()->set("i", Value(i), tick->getTree()->getId(), this->getId());
    
    return status;
}

NS_B3_END