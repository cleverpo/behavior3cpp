//
//  RanPriority.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/8.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef RanPriority_hpp
#define RanPriority_hpp

#include "core/Composite.hpp"

NS_B3_BEGIN

class MemRanPriority : public Composite{

public:
    MemRanPriority();
    MemRanPriority(Value* properties);
    virtual ~MemRanPriority();
    
protected:
    virtual void open(Tick* tick) override;
    virtual State tick(Tick* tick) override;
    virtual int randomChoose(int count);

private:
    int m_maxLoop;
    int m_loop;
};

NS_B3_END

#endif /* RanPriority_hpp */
