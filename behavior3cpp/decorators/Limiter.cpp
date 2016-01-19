//
//  Limiter.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "Limiter.hpp"
#include "core/Tick.hpp"
#include "core/BehaviorTree.hpp"

NS_B3_BEGIN

Limiter::Limiter():
m_maxLoop(0)
{
    m_name = "Limiter";
}

Limiter::Limiter(Value* properties):
m_maxLoop(0)
{
    m_name = "Limiter";
    m_maxLoop = properties->asMap()["maxLoop"].asInt();
}

Limiter::~Limiter(){}

void Limiter::open(Tick* tick){
    tick->getBlackBoard()->set("i", Value(0), tick->getTree()->getId(), this->getId());
}

State Limiter::tick(Tick* tick){
    if(!this->m_child)
        return State::ERROR;
    
    int i = tick->getBlackBoard()->get("i", tick->getTree()->getId(), this->getId()).asInt();
    
    if(i < this->m_maxLoop){
        State status = this->m_child->_execute(tick);
        
        if(status == State::SUCCESS || status == State::FAILURE)
            tick->getBlackBoard()->set("i", i + 1, tick->getTree()->getId(), this->getId());
        
        return status;
    }
    
    return State::FAILURE;
}

NS_B3_END