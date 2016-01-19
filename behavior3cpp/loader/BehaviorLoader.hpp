//
//  BehaviorLoader.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/6.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef BehaviorLoader_hpp
#define BehaviorLoader_hpp

#include "core/BehaviorTree.hpp"
#include "core/Value.hpp"
#include "core/BaseNode.hpp"

NS_B3_BEGIN

class BehaviorLoader{

public:
    virtual void loadFromJson(BehaviorTree* tree, const std::string& jsonFile) = 0;
    
protected:
    virtual BaseNode* createNodeByName(const std::string& name, Value* properties);
};

NS_B3_END

#endif /* BehaviorLoader_hpp */
