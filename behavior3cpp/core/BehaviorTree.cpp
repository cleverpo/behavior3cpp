//
//  BehaviorTree.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "BehaviorTree.hpp"
#include <math.h>
#include <stack>

NS_B3_BEGIN

BehaviorTree::BehaviorTree():
m_root(nullptr),
m_blackBoard(nullptr),
m_target(nullptr),
m_tick(nullptr)
{
    m_name = "The Behavior Tree";
    m_description = "Default Description";
    m_tick = new Tick();
}

BehaviorTree::~BehaviorTree(){
    if(m_tick){
        delete m_tick;
        m_tick = nullptr;
    }
    
    if(m_root){
        delete m_root;
        m_root = nullptr;
    }
}

State BehaviorTree::tick(Value* target, Blackboard* blackBoard, float deltaTime){
//    m_tick->reset();
    m_tick->setTarget(target);
    m_tick->setBlackBoard(blackBoard);
    m_tick->setTree(this);
    m_tick->setDeltaTime(deltaTime);
    
    State ret = this->m_root->_execute(m_tick);
    
    std::vector<Value>& lastOpenNodes = blackBoard->get("openNodes", this->getId()).asVector();
    std::vector<Value>& curOpenNodes = m_tick->getOpenNodes();
    
    int start = 0;
    int length = lastOpenNodes.size() < curOpenNodes.size() ? (int)lastOpenNodes.size() : (int)curOpenNodes.size();
    
    for(int i = 0; i < length; i++){
        start = i + 1;
        if(lastOpenNodes[i] != curOpenNodes[i])
            break;
    }
    
    for(int i = (int)lastOpenNodes.size() - 1; i >= start; i--){
        BaseNode* baseNode = (BaseNode*)lastOpenNodes[i].asObject();
        baseNode->_close(m_tick);
    }
    
    blackBoard->set("openNodes", Value(curOpenNodes), this->getId());
    
    return ret;
}

void BehaviorTree::dump(){
    if(!m_root)
        return;
    
    char buffer[1024];
    char space[64];
    std::stack<BaseNode*> stack;
    stack.push(m_root);
    
    sprintf(space, "");
    
    while(stack.size() > 0){
        BaseNode* node = stack.top();
        stack.pop();
        
        if(node->getCategory() == COMPOSITE){
            
        }else if(node->getCategory() == DECORATOR){
            
        }else{
            sprintf(buffer, "%s{\n%s id:%s\n%s name:%s\n%s description:%s\n%s}\n", space, space, node->getId().c_str(), space, node->getName().c_str(), space, node->getDescription().c_str(), space);
        }
    }
}

NS_B3_END