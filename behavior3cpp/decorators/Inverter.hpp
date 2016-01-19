//
//  Inverter.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Inverter_hpp
#define Inverter_hpp

#include "core/Decorator.hpp"

NS_B3_BEGIN

class Inverter : public Decorator{

public:
    Inverter();
    Inverter(Value* properties);
    virtual ~Inverter();
    
protected:
    virtual State tick(Tick* tick) override;
    
};

NS_B3_END

#endif /* Inverter_hpp */
