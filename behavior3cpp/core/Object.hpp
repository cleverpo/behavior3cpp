//
//  Object.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/5.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include "b3.hpp"
#include "Value.hpp"

NS_B3_BEGIN

class Object{
    
public:
    Object();
    virtual ~Object(){};

public:
    std::string getId(){ return m_id; }
    std::string getName(){ return m_name; }
    std::string getCategory(){ return m_category; }
    std::string getTitle(){ return m_title; }
    std::string getDescription(){ return m_description; }
    
public:
    void setId(const std::string& id){ m_id = id; }
    void setTitle(const std::string& title){ m_title = title; }
    void setDescription(const std::string& description){ m_description = description; }
    void setProperties(Value* property){
        if(!property || property->isNull())
            return;
        
        m_properties = property->asMap();
    }
    
protected:
    std::string m_id;
    std::string m_name;
    std::string m_category;
    std::string m_title;
    std::string m_description;
    std::map<std::string, Value> m_properties;
};

NS_B3_END

#endif /* Object_hpp */
