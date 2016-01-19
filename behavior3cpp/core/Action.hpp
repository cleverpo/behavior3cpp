//
//  Action.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Action_hpp
#define Action_hpp

#include "BaseNode.hpp"

NS_B3_BEGIN

class Action : public BaseNode{

public:
    Action(){
        m_category = ACTION;
    }
    
    virtual ~Action(){};
    
};

NS_B3_END

#endif /* Action_hpp */
