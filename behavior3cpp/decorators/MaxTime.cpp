//
//  MaxTime.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "MaxTime.hpp"
#include "core/Tick.hpp"
#include "core/BehaviorTree.hpp"

NS_B3_BEGIN

MaxTime::MaxTime():
m_maxTime(0.f)
{
    m_name = "MaxTime";
}

MaxTime::MaxTime(Value* properties):
m_maxTime(0.f)
{
    m_name = "MaxTime";
    m_maxTime = properties->asMap()["maxTime"].asFloat();
}

MaxTime::~MaxTime(){
}

void MaxTime::open(Tick* tick){
    tick->getBlackBoard()->set("startTime", Value(0.f), tick->getTree()->getId(), this->getId());
}

State MaxTime::tick(Tick* tick){
    if(!this->m_child)
        return State::ERROR;
    
    float curTime = tick->getBlackBoard()->get("startTime", tick->getTree()->getId(), this->getId()).asFloat();
    
    if(curTime < this->m_maxTime){
        State status = this->m_child->_execute(tick);
        tick->getBlackBoard()->set("startTime", curTime + tick->getDeltaTime(), tick->getTree()->getId(), this->getId());
        
        return status;
    }
    
    return State::FAILURE;
    
}

NS_B3_END