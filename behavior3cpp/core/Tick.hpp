//
//  Tick.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Tick_hpp
#define Tick_hpp

#include "b3.hpp"
#include "Blackboard.hpp"
#include "BaseNode.hpp"

NS_B3_BEGIN

class BehaviorTree;
class Tick{
    
    friend class BaseNode;
    
public:
    Tick();
    
public:
    void reset();
    
public:
    void setDeltaTime(float delta){ m_deltaTime = delta; }
    float getDeltaTime(){ return m_deltaTime; }
    
    void setBlackBoard(Blackboard* blackboard){ m_blackBoard = blackboard; }
    Blackboard* getBlackBoard(){ return m_blackBoard; }
    
    void setTree(BehaviorTree* tree){ m_behaviorTree = tree; }
    BehaviorTree* getTree(){ return m_behaviorTree; }
    
    void setTarget(Value* target){ m_target = target; }
    Value* getTarget(){ return m_target; }
    
    std::vector<Value>& getOpenNodes(){ return m_openNodes; }
    
protected:
    void _enterNode(BaseNode* node);
    void _openNode(BaseNode* node);
    void _tickNode(BaseNode* node);
    void _closeNode(BaseNode* node);
    void _exitNode(BaseNode* node);
    
private:
    //每次Tick的时间间隔
    float m_deltaTime;
    
private:
    Blackboard* m_blackBoard;
    BehaviorTree* m_behaviorTree;
    Value* m_target;
    std::vector<Value> m_openNodes;
};

NS_B3_END

#endif /* Tick_hpp */
