//
//  Wait.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Wait_hpp
#define Wait_hpp

#include "core/Action.hpp"

NS_B3_BEGIN

class Wait : public Action{

public:
    Wait();
    Wait(Value* properties);
    virtual ~Wait();
    
protected:
    virtual void open(Tick* tick) override;
    virtual State tick(Tick* tick) override;
    
private:
    //second
    float m_endTime;
};

NS_B3_END

#endif /* Wait_hpp */
