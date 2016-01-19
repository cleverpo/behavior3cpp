//
//  MaxTime.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef MaxTime_hpp
#define MaxTime_hpp

#include "core/Decorator.hpp"

NS_B3_BEGIN

class MaxTime : public Decorator{

public:
    MaxTime();
    MaxTime(Value* properties);
    virtual ~MaxTime();
    
protected:
    virtual void open(Tick* tick) override;
    virtual State tick(Tick* tick) override;
    
private:
    float m_maxTime;
};

NS_B3_END

#endif /* MaxTime_hpp */
