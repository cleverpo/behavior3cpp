//
//  RanRepeater.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/11.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "RanRepeater.hpp"
#include "core/Tick.hpp"
#include "core/BehaviorTree.hpp"

NS_B3_BEGIN

RanRepeater::RanRepeater():
m_maxLoop(-1)
{
    m_name = "RanRepeater";
}

RanRepeater::RanRepeater(Value* properties):
m_maxLoop(-1)
{
    m_name = "RanRepeater";
    m_maxLoop = properties->asMap()["maxLoop"].asInt();
}

RanRepeater::~RanRepeater(){
}

void RanRepeater::open(Tick* tick){
    tick->getBlackBoard()->set("i", Value(0), tick->getTree()->getId(), this->getId());
    
    float rand = std::rand() / (float)RAND_MAX;
    int l = ceil(rand * m_maxLoop);
    tick->getBlackBoard()->set("loop", l, tick->getTree()->getId(), this->getId());
}

State RanRepeater::tick(Tick* tick){
    if(!this->m_child)
        return State::ERROR;
    
    State status = State::SUCCESS;
    int i = tick->getBlackBoard()->get("i", tick->getTree()->getId(), this->getId()).asInt();
    int loop = tick->getBlackBoard()->get("loop", tick->getTree()->getId(), this->getId()).asInt();
    
    while(loop < 0 || i < loop){
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