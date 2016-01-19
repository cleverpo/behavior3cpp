//
//  BehaviorLoader.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/6.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "BehaviorLoader.hpp"
#include "composites/Sequence.hpp"
#include "composites/Priority.hpp"
#include "composites/Parallel.hpp"
#include "composites/MemSequence.hpp"
#include "composites/MemPriority.hpp"
#include "composites/MemRanPriority.hpp"
#include "actions/Succeeder.hpp"
#include "actions/Failer.hpp"
#include "actions/Runner.hpp"
#include "actions/Error.hpp"
#include "actions/Wait.hpp"
#include "decorators/Inverter.hpp"
#include "decorators/Limiter.hpp"
#include "decorators/MaxTime.hpp"
#include "decorators/Repeater.hpp"
#include "decorators/RanRepeater.hpp"
#include "decorators/RepeatUntilFailure.hpp"
#include "decorators/RepeatUntilSuccess.hpp"
#include <assert.h>

NS_B3_BEGIN

BaseNode* BehaviorLoader::createNodeByName(const std::string& name, Value* properties){
    BaseNode* ret = nullptr;
    
    if(name == "Sequence"){
        ret = new Sequence(properties);
    }else if(name == "Priority"){
        ret = new Priority(properties);
    }else if(name == "Parallel"){
        ret = new Parallel(properties);
    }else if(name == "MemSequence"){
        ret = new MemSequence(properties);
    }else if(name == "MemPriority"){
        ret = new MemPriority(properties);
    }else if(name == "MemRanPriority"){
        ret = new MemRanPriority(properties);
    }else if(name == "Succeeder"){
        ret = new Succeeder(properties);
    }else if(name == "Failer"){
        ret = new Failer(properties);
    }else if(name == "Runner"){
        ret = new Runner(properties);
    }else if(name == "Error"){
        ret = new Error(properties);
    }else if(name == "Wait"){
        ret = new Wait(properties);
    }else if(name == "Inverter"){
        ret = new Inverter(properties);
    }else if(name == "Limiter"){
        ret = new Limiter(properties);
    }else if(name == "MaxTime"){
        ret = new MaxTime(properties);
    }else if(name == "Repeater"){
        ret = new Repeater(properties);
    }else if(name == "RanRepeater"){
        ret = new RanRepeater(properties);
    }else if(name == "RepeatUntilFailure"){
        ret = new RepeatUntilFailure(properties);
    }else if(name == "RepeatUntilSuccess"){
        ret = new RepeatUntilSuccess(properties);
    }else{
        assert("wrong node type in loading BehaviorTree");
    }
    
    return ret;
}

NS_B3_END