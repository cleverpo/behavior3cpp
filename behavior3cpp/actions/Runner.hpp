//
//  Runner.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Runner_hpp
#define Runner_hpp

#include "core/Action.hpp"

NS_B3_BEGIN

class Runner : public Action{

public:
    Runner();
    Runner(Value* properties);
    virtual ~Runner();
    
protected:
    virtual State tick(Tick* tick) override;
    
};

NS_B3_END

#endif /* Runner_hpp */
