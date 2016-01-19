//
//  Decorator.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Decorator_hpp
#define Decorator_hpp

#include "BaseNode.hpp"

NS_B3_BEGIN

class Decorator : public BaseNode{
    
public:
    Decorator()
    {
        m_category = DECORATOR;
    }
    
    Decorator(Value* property):
    m_child(NULL)
    {
        m_category = DECORATOR;
    }
    virtual ~Decorator(){
        if(m_child){
            delete m_child;
            m_child = nullptr;
        }
    }
    
public:
    void setChild(BaseNode* child){
        m_child = child;
    }
    
protected:
    BaseNode* m_child;
};

NS_B3_END

#endif /* Decorator_hpp */
