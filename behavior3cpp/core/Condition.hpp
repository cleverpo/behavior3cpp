//
//  Condition.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Condition_hpp
#define Condition_hpp

#include "BaseNode.hpp"

NS_B3_BEGIN

class Condition : public BaseNode{
    
public:
    Condition(){
        m_category = CONDITION;
    }
    
    virtual ~Condition(){};
};

NS_B3_END

#endif /* Condition_hpp */
