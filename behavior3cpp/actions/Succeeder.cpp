//
//  Succeeder.cpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/7.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#include "Succeeder.hpp"

NS_B3_BEGIN

Succeeder::Succeeder(){
    m_name = "Succeeder";
}

Succeeder::Succeeder(Value* properties){
    m_name = "Succeeder";
}

Succeeder::~Succeeder(){

}

State Succeeder::tick(Tick* tick){
    return State::SUCCESS;
}

NS_B3_END