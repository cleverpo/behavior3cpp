//
//  BehaviorTree.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef BehaviorTree_hpp
#define BehaviorTree_hpp

#include "b3.hpp"
#include "Object.hpp"
#include "Blackboard.hpp"
#include "BaseNode.hpp"
#include "Tick.hpp"

NS_B3_BEGIN

class BehaviorTreeLoader;
class BehaviorTree : public Object{
    
    friend class BehaviorTreeLoader;
    
public:
    BehaviorTree();
    virtual ~BehaviorTree();
    
public:
    void setRoot(BaseNode* root){ m_root = root; }
    
public:
    State tick(Value* target, Blackboard* blackBoard, float deltaTime);
    void dump();
    
private:
    BaseNode* m_root;
    Blackboard* m_blackBoard;
    Value* m_target;
    Tick* m_tick;
};

NS_B3_END

#endif /* BehaviorTree_hpp */
