//
//  Parallel.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/8.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "Parallel.hpp"

NS_B3_BEGIN

Parallel::Parallel():
m_successCount(0),
m_failureCount(0)
{
    m_name = "Parallel";
}

Parallel::Parallel(Value* properties):
m_successCount(0),
m_failureCount(0)
{
    m_name = "Parallel";
    m_successCount = properties->asMap()["S"].asInt();
    m_failureCount = properties->asMap()["F"].asInt();
}

Parallel::~Parallel(){

}

State Parallel::tick(Tick* tick){
    int successCount = 0;
    int failureCount = 0;
    
    for(int i = 0; i < m_children.size(); i++){
        BaseNode* child = m_children[i];
        State status = child->_execute(tick);
        
        if(status == State::SUCCESS)
            successCount++;
        else if(status == State::FAILURE)
            failureCount++;
    }
    
    if(successCount >= m_successCount)
        return State::SUCCESS;
    else if(failureCount >= m_failureCount)
        return State::FAILURE;
    else
        return State::RUNNING;
}

NS_B3_END