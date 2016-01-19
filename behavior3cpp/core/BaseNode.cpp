//
//  BaseNode.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "BaseNode.hpp"
#include "Tick.hpp"
#include "BehaviorTree.hpp"

NS_B3_BEGIN

BaseNode::BaseNode(){
}

BaseNode::~BaseNode(){

}

State BaseNode::_execute(Tick* tick){
    this->_enter(tick);
    
    if(!tick->getBlackBoard()->get("isOpen", tick->getTree()->getId(), this->getId()).asBool()){
        this->_open(tick);
    }
    
    State status = this->_tick(tick);
    
    if(status != State::RUNNING){
        this->_close(tick);
    }
    
    this->_exit(tick);
    
    return status;
}

void BaseNode::_enter(Tick* tick){
    tick->_enterNode(this);
    this->enter(tick);
}

void BaseNode::_open(Tick* tick){
    tick->_openNode(this);
    tick->getBlackBoard()->set("isOpen", Value(true), tick->getTree()->getId(), this->getId());
    this->open(tick);
}

State BaseNode::_tick(Tick* tick){
    tick->_tickNode(this);
    
    return this->tick(tick);
}

void BaseNode::_close(Tick* tick){
    tick->_closeNode(this);
    tick->getBlackBoard()->set("isOpen", Value(false), tick->getTree()->getId(), this->getId());
    this->close(tick);
}

void BaseNode::_exit(Tick* tick){
    tick->_exitNode(this);
    this->exit(tick);
}

NS_B3_END