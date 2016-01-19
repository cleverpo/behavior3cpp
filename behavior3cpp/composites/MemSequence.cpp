//
//  MemSequence.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "MemSequence.hpp"
#include "core/Tick.hpp"
#include "core/BehaviorTree.hpp"

NS_B3_BEGIN

MemSequence::MemSequence(){
    m_name = "MemSequence";
}

MemSequence::MemSequence(Value* property){
    m_name = "MemSequence";
}

MemSequence::~MemSequence(){

}

void MemSequence::open(Tick* tick){
    tick->getBlackBoard()->set("runningChild", Value(0), tick->getTree()->getId(), this->getId());
}

State MemSequence::tick(Tick* tick){
    int lastRunningChild = tick->getBlackBoard()->get("runningChild", tick->getTree()->getId(), this->getId()).asInt();
    
    for(int i = lastRunningChild; i < m_children.size(); i++){
        BaseNode* child = m_children[i];
        State status = child->_execute(tick);
        
        if(status != State::SUCCESS){
            if(status == State::RUNNING){
                tick->getBlackBoard()->set("runningChild", Value(i), tick->getTree()->getId(), this->getId());
            }
            
            return status;
        }
    }
    
    return State::SUCCESS;
}

NS_B3_END