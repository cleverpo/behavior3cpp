//
//  MemPriority.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef MemPriority_hpp
#define MemPriority_hpp

#include "Composite.hpp"

NS_B3_BEGIN

class MemPriority : public Composite{

public:
    MemPriority();
    MemPriority(Value* property);
    virtual ~MemPriority();
    
protected:
    virtual void open(Tick* tick) override;
    virtual State tick(Tick* tick) override;
};

NS_B3_END

#endif /* MemPriority_hpp */
