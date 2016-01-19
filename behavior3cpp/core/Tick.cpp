//
//  Tick.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "Tick.hpp"

NS_B3_BEGIN

Tick::Tick():
m_deltaTime(0.f),
m_blackBoard(nullptr),
m_behaviorTree(nullptr),
m_target(nullptr)
{
    
}

void Tick::reset(){
    m_openNodes.clear();
}

void Tick::_enterNode(BaseNode* node){
    
}

void Tick::_openNode(BaseNode* node){
    this->m_openNodes.push_back(Value(node));
}

void Tick::_tickNode(BaseNode* node){

}

void Tick::_closeNode(BaseNode* node){
    if(m_openNodes.size() == 0)
        return;
    
    std::vector<Value>::iterator it = std::find(this->m_openNodes.begin(), this->m_openNodes.end(), Value(node));
    if(it != m_openNodes.end())
        this->m_openNodes.erase(it);
}

void Tick::_exitNode(BaseNode* node){

}

NS_B3_END