//
//  Value.hpp
//  behavior3cpp
//
//  Created by luozhipeng on 16/1/4.
//  Copyright © 2016年 luozhipeng. All rights reserved.
//

#ifndef Value_hpp
#define Value_hpp

#include "b3.hpp"
#include <map>
#include <vector>

NS_B3_BEGIN

class Value{
    
public:
    static const Value Null;
    
public:
    enum class Type
    {
        NONE = 0,
        INT,
        FLOAT,
        BOOL,
        STRING,
        MAP,
        VECTOR,
        OBJECT
    };
    
public:
    Value():
    _type(Type::NONE),
    _strV(nullptr),
    _mapV(nullptr),
    _vectorV(nullptr)
    {};
    
    Value(const Value& value):
    _type(Type::NONE),
    _strV(nullptr),
    _mapV(nullptr),
    _vectorV(nullptr)
    {
        *this = value;
    };
    
    Value(const Type& type):
    _type(type),
    _strV(nullptr),
    _mapV(nullptr),
    _vectorV(nullptr)
    {
        this->setType(type);
    };
    
    Value(int value):
    _type(Type::NONE),
    _strV(nullptr),
    _mapV(nullptr),
    _vectorV(nullptr)
    {
        this->setInt(value);
    };
    
    Value(float value):
    _type(Type::NONE),
    _strV(nullptr),
    _mapV(nullptr),
    _vectorV(nullptr)
    {
        this->setFloat(value);
    };
    
    Value(bool value):
    _type(Type::NONE),
    _strV(nullptr),
    _mapV(nullptr),
    _vectorV(nullptr)
    {
        this->setBool(value);
    };
    
    Value(const std::string& value):
    _type(Type::NONE),
    _strV(nullptr),
    _mapV(nullptr),
    _vectorV(nullptr)
    {
        this->setString(value);
    };
    
    Value(const std::map<std::string, Value>& value):
    _type(Type::NONE),
    _strV(nullptr),
    _mapV(nullptr),
    _vectorV(nullptr)
    {
        this->setMap(value);
    };
    
    Value(const std::vector<Value>& value):
    _type(Type::NONE),
    _strV(nullptr),
    _mapV(nullptr),
    _vectorV(nullptr)
    {
        this->setVector(value);
    };
    
    Value(void* value):
    _type(Type::NONE),
    _strV(nullptr),
    _mapV(nullptr),
    _vectorV(nullptr)
    {
        this->setObject(value);
    };
    
    virtual ~Value(){
        this->clear();
    }
    
public:
    template<typename T>
    void set(T value){
        
    }
    
    void setType(const Type& type){
        this->clear();
        
        _type = type;
        
        switch (_type) {
            case Type::MAP:
            {
                _mapV = new std::map<std::string, Value>();
            }
                break;
                
            case Type::VECTOR:
            {
                _vectorV = new std::vector<Value>();
            }
                break;
                
            case Type::STRING:
            {
                _strV = new std::string("");
            }
                
            default:
                break;
        }
    }
    
    void setInt(int value){
        _type = Type::INT;
        _value._intV = value;
    }
    
    void setFloat(float value){
        _type = Type::FLOAT;
        _value._floatV = value;
    }
    
    void setBool(bool value){
        _type = Type::BOOL;
        _value._boolV = value;
    }
    
    void setString(const std::string& value){
        _type = Type::STRING;
        if(_strV){
            delete _strV;
            _strV = nullptr;
        }
        _strV = new std::string(value);
    }
    
    void setMap(const std::map<std::string, Value>& value){
        _type = Type::MAP;
        if(_mapV){
            delete _mapV;
            _mapV = nullptr;
        }
        
        _mapV = new std::map<std::string, Value>(value);
    }
    
    void setVector(const std::vector<Value>& value){
        _type = Type::VECTOR;
        if(_vectorV){
            delete _vectorV;
            _vectorV = nullptr;
        }
        
        _vectorV = new std::vector<Value>(value);
    }
    
    void setObject(void* object){
        _type = Type::OBJECT;
        _value._objectV = object;
    }
    
    int asInt(){ return _value._intV; }
    float asFloat(){ return _value._floatV; }
    bool asBool(){ return _value._boolV; }
    std::string asString(){ return *_strV; }
    std::map<std::string, Value>& asMap(){ return *_mapV; }
    std::vector<Value>& asVector(){ return *_vectorV; }
    void* asObject(){ return _value._objectV; }
    
    bool isNull(){ return _type == Type::NONE; }
    
public:
    Value& operator= (const Value& value){
        this->_type = value._type;
        this->_value = value._value;

        if(value._mapV){
            this->_mapV = new std::map<std::string, Value>(*value._mapV);
        }
        
        if(value._vectorV){
            this->_vectorV = new std::vector<Value>(*value._vectorV);
        }
        
        if(value._strV){
            this->_strV = new std::string(*value._strV);
        }
        
        return *this;
    };
    
    bool operator!= (const Value& v){
        return !(*this == v);
    }
    
    bool operator!= (const Value& v) const {
        return !(*this == v);
    }
    
    bool operator== (const Value& v){
        const Value& value = *this;
        return value == v;
    }
    
    bool operator== (const Value& v) const {
        if (this == &v) return true;
        if (v._type != this->_type) return false;
        
        switch (_type)
        {
            case Type::INT:    return v._value._intV   == this->_value._intV;
            case Type::FLOAT: return v._value._floatV    == this->_value._floatV;
            case Type::BOOL: return v._value._boolV   == this->_value._boolV;
            case Type::STRING:  return *v._strV   == *this->_strV;
            case Type::OBJECT: return v._value._objectV == this->_value._objectV;
            case Type::VECTOR:
            {
                const auto &v1 = *(this->_vectorV);
                const auto &v2 = *(v._vectorV);
                const auto size = v1.size();
                
                if (size != v2.size())
                    return false;
                
                for (size_t i = 0; i < size; i++)
                {
                    if (v1[i] != v2[i]) return false;
                }
                
                return true;
            }
            case Type::MAP:
            {
                const auto &map1 = *(this->_mapV);
                const auto &map2 = *(v._mapV);
                for (const auto &kvp : map1)
                {
                    auto it = map2.find(kvp.first);
                    if (it == map2.end() || it->second != kvp.second)
                    {
                        return false;
                    }
                }
                return true;
            }
            
            default:
                break;
        };
        
        return false;

    }
    
private:
    void clear(){
        switch (_type) {
            case Type::INT:
            {
                _value._intV = 0;
            }
                break;
                
            case Type::FLOAT:
            {
                _value._floatV = 0.f;
            }
                break;
                
            case Type::BOOL:
            {
                _value._boolV = false;
            }
                break;
                
            case Type::STRING:
            {
                if(_strV){
                    delete _strV;
                    _strV = nullptr;
                }
            }
                break;
                
            case Type::MAP:
            {
                if(_mapV){
                    delete _mapV;
                    _mapV = nullptr;
                }
            }
                break;
                
            case Type::VECTOR:
            {
                if(_vectorV){
                    delete _vectorV;
                    _vectorV = nullptr;
                }
            }
                break;
                
            case Type::OBJECT:
            {
                _value._objectV = nullptr;
            }
                break;
                
            default:
                break;
        }
        _type = Type::NONE;
    };
    
    
protected:
    Type _type;
    
    union U{
        int _intV;
        float _floatV;
        bool _boolV;
        void* _objectV;
        
        U() { memset( this, 0, sizeof(*this) ); }
        ~U(){}
        U& operator=( const U& other ) {
            memcpy(this, &other, sizeof(*this));
            return *this;
        }
    } _value;
    
    std::string* _strV;
    std::map<std::string, Value>* _mapV;
    std::vector<Value>* _vectorV;
};

NS_B3_END

#endif /* Value_hpp */
