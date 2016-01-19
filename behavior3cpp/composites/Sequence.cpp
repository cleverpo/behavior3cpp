//
//  Sequence.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "Sequence.hpp"

NS_B3_BEGIN

Sequence::Sequence(){
    m_name = "Sequence";
}

Sequence::Sequence(Value* property){
    m_name = "Sequence";
}

Sequence::~Sequence(){

}

State Sequence::tick(Tick* tick){
    for(int i = 0; i < m_children.size(); i++){
        BaseNode* child = m_children[i];
        State status = child->_execute(tick);
        
        if(status != State::SUCCESS)
            return status;
    }
    
    return State::SUCCESS;
}

NS_B3_END