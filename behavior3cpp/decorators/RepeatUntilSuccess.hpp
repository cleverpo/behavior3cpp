//
//  RepeatUnitlSuccess.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef RepeatUnitlSuccess_hpp
#define RepeatUnitlSuccess_hpp

#include "core/Decorator.hpp"

NS_B3_BEGIN

class RepeatUntilSuccess : public Decorator{
    
public:
    RepeatUntilSuccess();
    RepeatUntilSuccess(Value* properties);
    virtual ~RepeatUntilSuccess();
    
protected:
    virtual void open(Tick* tick) override;
    virtual State tick(Tick* tick) override;
    
private:
    int m_maxLoop;
};

NS_B3_END

#endif /* RepeatUnitlSuccess_hpp */
