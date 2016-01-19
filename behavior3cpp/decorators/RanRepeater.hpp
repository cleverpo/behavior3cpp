//
//  RanRepeater.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/11.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef RanRepeater_hpp
#define RanRepeater_hpp

#include "core/Decorator.hpp"

NS_B3_BEGIN

class RanRepeater : public Decorator{
    
public:
    RanRepeater();
    RanRepeater(Value* properties);
    virtual ~RanRepeater();
    
protected:
    virtual void open(Tick* tick) override;
    virtual State tick(Tick* tick) override;
    
private:
    int m_maxLoop;
};

NS_B3_END

#endif /* RanRepeater_hpp */
