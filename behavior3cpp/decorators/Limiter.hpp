//
//  Limiter.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Limiter_hpp
#define Limiter_hpp

#include "core/Decorator.hpp"

NS_B3_BEGIN

class Limiter : public Decorator{

public:
    Limiter();
    Limiter(Value* properties);
    virtual ~Limiter();
    
protected:
    virtual void open(Tick* tick) override;
    virtual State tick(Tick* tick) override;
    
private:
    int m_maxLoop;
};

NS_B3_END

#endif /* Limiter_hpp */
