//
//  Priority.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "Priority.hpp"

NS_B3_BEGIN

Priority::Priority(){
    m_name = "Priority";
}

Priority::Priority(Value* property){
    m_name = "Priority";
}

Priority::~Priority(){

}

State Priority::tick(Tick* tick){
    for(int i = 0; i < m_children.size(); i++){
        BaseNode* child = m_children[i];
        State status = child->_execute(tick);
        
        if(status != State::FAILURE)
            return status;
    }
    
    return State::FAILURE;
}

NS_B3_END