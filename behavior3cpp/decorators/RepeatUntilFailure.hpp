//
//  RepeatUntilFailure.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef RepeatUntilFailure_hpp
#define RepeatUntilFailure_hpp

#include "core/Decorator.hpp"

NS_B3_BEGIN

class RepeatUntilFailure : public Decorator{
    
public:
    RepeatUntilFailure();
    RepeatUntilFailure(Value* properties);
    virtual ~RepeatUntilFailure();
    
protected:
    virtual void open(Tick* tick) override;
    virtual State tick(Tick* tick) override;
    
private:
    int m_maxLoop;
};

NS_B3_END

#endif /* RepeatUntilFailure_hpp */
