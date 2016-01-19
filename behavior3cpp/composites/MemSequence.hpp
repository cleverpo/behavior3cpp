//
//  MemSequence.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef MemSequence_hpp
#define MemSequence_hpp

#include "Composite.hpp"

NS_B3_BEGIN

class MemSequence : public Composite{

public:
    MemSequence();
    MemSequence(Value* property);
    virtual ~MemSequence();
    
protected:
    virtual void open(Tick* tick) override;
    virtual State tick(Tick* tick) override;
    
};

NS_B3_END

#endif /* MemSequence_hpp */
