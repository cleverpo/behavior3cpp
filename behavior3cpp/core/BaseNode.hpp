//
//  BaseNode.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef BaseNode_hpp
#define BaseNode_hpp

#include <string>
#include <map>
#include "Value.hpp"
#include "Object.hpp"

NS_B3_BEGIN

class Tick;
class BaseNode : public Object{
    
    friend class BehaviorTree;
    friend class Sequence;
    friend class Priority;
    friend class Parallel;
    friend class MemSequence;
    friend class MemPriority;
    friend class MemRanPriority;
    friend class Inverter;
    friend class Limiter;
    friend class MaxTime;
    friend class Repeater;
    friend class RanRepeater;
    friend class RepeatUntilFailure;
    friend class RepeatUntilSuccess;
    
public:
    BaseNode();
    virtual ~BaseNode();
    
protected:
    virtual void enter(Tick* tick){};
    virtual void open(Tick* tick){};
    virtual State tick(Tick* tick){ return State::NONE; };
    virtual void close(Tick* tick){};
    virtual void exit(Tick* tick){};
    
protected:
    State _execute(Tick* tick);
    void _enter(Tick* tick);
    void _open(Tick* tick);
    State _tick(Tick* tick);
    void _close(Tick* tick);
    void _exit(Tick* tick);
    
private:
    std::map<std::string, Value> m_parameters;
};

NS_B3_END

#endif /* BaseNode_hpp */
