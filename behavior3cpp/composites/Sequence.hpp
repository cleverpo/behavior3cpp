//
//  Sequence.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Sequence_hpp
#define Sequence_hpp

#include "Composite.hpp"

NS_B3_BEGIN

class Sequence : public Composite{

public:
    Sequence();
    Sequence(Value* property);
    virtual ~Sequence();
    
protected:
    virtual State tick(Tick* tick) override;
    
};

NS_B3_END

#endif /* Sequence_hpp */
