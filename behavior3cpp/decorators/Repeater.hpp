//
//  Repeater.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Repeater_hpp
#define Repeater_hpp

#include "core/Decorator.hpp"

NS_B3_BEGIN

class Repeater : public Decorator{

public:
    Repeater();
    Repeater(Value* properties);
    virtual ~Repeater();
    
protected:
    virtual void open(Tick* tick) override;
    virtual State tick(Tick* tick) override;
    
private:
    int m_maxLoop;
};

NS_B3_END

#endif /* Repeater_hpp */
