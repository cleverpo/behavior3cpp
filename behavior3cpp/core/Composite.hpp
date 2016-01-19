//
//  Composite.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Composite_hpp
#define Composite_hpp

#include "BaseNode.hpp"

NS_B3_BEGIN

class Composite : public BaseNode{

public:
    Composite(){
        m_category = COMPOSITE;
    }
    
    Composite(Value* property){
    };
    
    virtual ~Composite(){
        for(int i = 0; i < m_children.size(); i++){
            if(m_children[i]){
                delete m_children[i];
            }
        }
    };
    
public:
    void pushChild(BaseNode* child){
        m_children.push_back(child);
    };
    
protected:
    std::vector<BaseNode*> m_children;
};

NS_B3_END

#endif /* Composite_hpp */
