//
//  Priority.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Priority_hpp
#define Priority_hpp

#include "Composite.hpp"

NS_B3_BEGIN

class Priority : public Composite{
    
public:
    Priority();
    Priority(Value* property);
    virtual ~Priority();
    
protected:
    virtual State tick(Tick* tick) override;
};

NS_B3_END

#endif /* Priority_hpp */
