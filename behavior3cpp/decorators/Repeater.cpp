//
//  Repeater.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "Repeater.hpp"
#include "core/Tick.hpp"
#include "core/BehaviorTree.hpp"

NS_B3_BEGIN

Repeater::Repeater():
m_maxLoop(-1)
{
    m_name = "Repeater";
}

Repeater::Repeater(Value* properties):
m_maxLoop(-1)
{
    m_name = "Repeater";
    m_maxLoop = properties->asMap()["maxLoop"].asInt();
}

Repeater::~Repeater(){
}

void Repeater::open(Tick* tick){
    tick->getBlackBoard()->set("i", Value(0), tick->getTree()->getId(), this->getId());
}

State Repeater::tick(Tick* tick){
    if(!this->m_child)
        return State::ERROR;
    
    State status = State::SUCCESS;
    int i = tick->getBlackBoard()->get("i", tick->getTree()->getId(), this->getId()).asInt();
    
    while(m_maxLoop < 0 || i < m_maxLoop){
        status = m_child->_execute(tick);
        
        if(status == State::SUCCESS || status == State::FAILURE)
            i++;
        else
            break;
    }
    
    tick->getBlackBoard()->set("i", Value(i), tick->getTree()->getId(), this->getId());
    
    return status;
}

NS_B3_END