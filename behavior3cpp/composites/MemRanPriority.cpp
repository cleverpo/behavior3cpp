//
//  RanPriority.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/8.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "MemRanPriority.hpp"
#include "core/Tick.hpp"
#include "core/BehaviorTree.hpp"

NS_B3_BEGIN

MemRanPriority::MemRanPriority():
m_maxLoop(0),
m_loop(0)
{
    m_name = "MemRanPriority";
}

MemRanPriority::MemRanPriority(Value* properties):
m_maxLoop(0),
m_loop(0)
{
    m_name = "MemRanPriority";
    m_maxLoop = properties->asMap()["MaxLoop"].asInt();
    m_loop = properties->asMap()["Loop"].asInt();
}

MemRanPriority::~MemRanPriority(){

}

void MemRanPriority::open(Tick* tick){
    tick->getBlackBoard()->set("runningChild", Value(-1), tick->getTree()->getId(), this->getId());
}

State MemRanPriority::tick(Tick* tick){
    int index = tick->getBlackBoard()->get("runningChild", tick->getTree()->getId(), this->getId()).asInt();
    if(index >= 0){
        State status = m_children[index]->_execute(tick);
        return status;
    }
    
    std::vector<int> indexes;
    for(int i = 0; i < m_children.size(); i++){
        indexes.push_back(i);
    }
    
    int loop = 0;
    if(m_loop != 0){
        loop = m_loop;
    }else if(m_maxLoop != 0){
        float rand = std::rand() / (float)RAND_MAX;
        int l = ceil(rand * m_maxLoop);
        
        loop = l == 0? 1 : l;
    }
    
    for(int i = 0; i < loop; i++){
        int index = this->randomChoose((int)indexes.size());
        if(index == -1)
            return State::FAILURE;
        
        int realIndex = indexes[index];
        BaseNode* child = m_children[realIndex];
        State status = child->_execute(tick);
        
        if(status != State::SUCCESS){
            if(status == State::RUNNING)
                tick->getBlackBoard()->set("runningChild", realIndex, tick->getTree()->getId(), this->getId());
            return status;
        }
        
        indexes.erase(std::find(indexes.begin(), indexes.end(), index));
    }
    
    return State::SUCCESS;
}

int MemRanPriority::randomChoose(int count){
    float rand = std::rand() / (float)RAND_MAX;
    int index = ceil(count * rand);
    
    return index - 1;
}

NS_B3_END