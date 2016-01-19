//
//  Failer.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Failer_hpp
#define Failer_hpp

#include "core/Action.hpp"

NS_B3_BEGIN

class Failer : public Action{

public:
    Failer();
    Failer(Value* properties);
    virtual ~Failer();
    
protected:
    virtual State tick(Tick* tick) override;
    
};

NS_B3_END

#endif /* Failer_hpp */
