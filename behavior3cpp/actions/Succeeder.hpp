//
//  Succeeder.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Succeeder_hpp
#define Succeeder_hpp

#include "core/Action.hpp"

NS_B3_BEGIN

class Succeeder : public Action{

public:
    Succeeder();
    Succeeder(Value* properties);
    virtual ~Succeeder();
    
protected:
    virtual State tick(Tick* tick) override;
    
};

NS_B3_END

#endif /* Succeeder_hpp */
