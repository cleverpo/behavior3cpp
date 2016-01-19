//
//  Parallel.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/8.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Parallel_hpp
#define Parallel_hpp

#include "core/Composite.hpp"

NS_B3_BEGIN

class Parallel : public Composite{

public:
    Parallel();
    Parallel(Value* properties);
    virtual ~Parallel();
    
protected:
    virtual State tick(Tick* tick) override;
    
private:
    int m_successCount;
    int m_failureCount;
};

NS_B3_END

#endif /* Parallel_hpp */
