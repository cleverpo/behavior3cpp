//
//  Blackboard.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/4.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Blackboard_hpp
#define Blackboard_hpp

#include "b3.hpp"
#include "Value.hpp"
#include <map>

NS_B3_BEGIN

class Blackboard{
    
public:
    Blackboard(){
        m_baseMemory.setType(Value::Type::MAP);
        m_treeMemory.setType(Value::Type::MAP);
    }
    
public:
    void set(const std::string& key, const Value& value, const std::string& treeId = "", const std::string& nodeId = ""){
        Value& v = this->getMemory(treeId, nodeId);
        
        v.asMap()[key] = value;
    }
    
    Value& get(const std::string& key, const std::string& treeId = "", const std::string& nodeId = ""){
        Value& v = this->getMemory(treeId, nodeId);
        
        return v.asMap()[key];
    }
    
private:
    Value& getTreeMemory(const std::string& treeId){
        Value& value = m_treeMemory.asMap()[treeId];
        
        if(value.isNull()){
            std::map<std::string, Value> map;
            map["nodeMemory"].setType(Value::Type::MAP);
            map["openNodes"].setType(Value::Type::VECTOR);
            map["traversalDepth"].setInt(0);
            map["traversalCycle"].setInt(0);
            
            value.setMap(map);
        }
        
        return value;
    }
    
    Value& getNodeMemory(const std::string& treeId, const std::string& nodeId){
        Value& nodeMemory = this->getTreeMemory(treeId).asMap()["nodeMemory"];
        Value& node = nodeMemory.asMap()[nodeId];
        
        if(node.isNull()){
            node.setType(Value::Type::MAP);
        }
        
        return node;
    }
    
    Value& getMemory(const std::string& treeId = "", const std::string& nodeId = ""){
        Value* ret = &this->m_baseMemory;
        
        if(treeId != ""){
            if(nodeId != ""){
                ret = &(this->getNodeMemory(treeId, nodeId));
            }else{
                ret = &(this->getTreeMemory(treeId));
            }
        }
        
        return *ret;
    }
    
private:
    Value m_baseMemory;
    Value m_treeMemory;
};

NS_B3_END

#endif /* Blackboard_hpp */
