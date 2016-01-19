//
//  Object.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "Object.hpp"

NS_B3_BEGIN

Object::Object():
m_id(""),
m_name(""),
m_category(""),
m_title(""),
m_description("")
{
    m_id = createUUID();
}

NS_B3_END