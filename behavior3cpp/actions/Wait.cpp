//
//  Wait.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "Wait.hpp"
#include "core/Tick.hpp"
#include "core/BehaviorTree.hpp"

NS_B3_BEGIN

Wait::Wait():
m_endTime(0.f)
{
    m_name = "Wait";
}

Wait::Wait(Value* properties):
m_endTime(0.f)
{
    m_name = "Wait";
    m_endTime = properties->asMap()["milliseconds"].asInt() / 1000.f;
}

Wait::~Wait(){

}

void Wait::open(Tick* tick){
    tick->getBlackBoard()->set("startTime", Value(0.f), tick->getTree()->getId(), this->getId());
}

State Wait::tick(Tick* tick){
    float time = tick->getBlackBoard()->get("startTime", tick->getTree()->getId(), this->getId()).asFloat();
    
    time += tick->getDeltaTime();
    
    if(time > m_endTime){
        return State::SUCCESS;
    }
    
    tick->getBlackBoard()->set("startTime", Value(time), tick->getTree()->getId(), this->getId());
    return State::RUNNING;
}

NS_B3_END