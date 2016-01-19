//
//  Error.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Error_hpp
#define Error_hpp

#include "core/Action.hpp"

NS_B3_BEGIN

class Error : public Action{

public:
    Error();
    Error(Value* properties);
    virtual ~Error();
    
protected:
    virtual State tick(Tick* tick) override;
    
};

NS_B3_END

#endif /* Error_hpp */
