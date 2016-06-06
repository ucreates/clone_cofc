//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef Parameter_h
#define Parameter_h

// stl
#include <map>
#include <string>

// cocos2d
#include "cocos2d.h"

// entity
#include "Value.h"
#include "BaseValue.h"

class Parameter {
   public:
    inline Parameter() {}

    inline ~Parameter() {
        this->clear();
        return;
    }

    template <typename T>
    inline T get(std::string name) {
        T t;
        if (this->parmeterMap.find(name) != this->parmeterMap.end()) {
            std::map<std::string, BaseValue*>::iterator it = this->parmeterMap.find(name);
            Value<T>* element = (Value<T>*)(*it).second;
            t = element->getValue();
            return t;
        }
        return t;
    }

    template <typename T>
    inline void set(std::string name, T parameter) {
        if (this->parmeterMap.find(name) == this->parmeterMap.end()) {
            Value<T>* element = new Value<T>();
            element->setValue(parameter);
            this->parmeterMap.insert(std::map<std::string, BaseValue*>::value_type(name, (BaseValue*)element));
        }
    }

    inline std::map<std::string, BaseValue*> getParmeterMap() { return this->parmeterMap; }

    inline void clear() {
        for (std::map<std::string, BaseValue*>::iterator it = this->parmeterMap.begin(); it != this->parmeterMap.end(); ++it) {
            CC_SAFE_DELETE(it->second);
        }
        this->parmeterMap.clear();
    }

    inline void copy(Parameter* parameter) {
        this->clear();
        std::map<std::string, BaseValue*> paramMap = parameter->getParmeterMap();
        for (std::map<std::string, BaseValue*>::iterator it = paramMap.begin(); it != paramMap.end(); it++) {
            std::string name = it->first;
            BaseValue* value = (BaseValue*)it->second;
            this->parmeterMap.insert(std::map<std::string, BaseValue*>::value_type(name, value->clone()));
        }
        return;
    }

   private:
    std::map<std::string, BaseValue*> parmeterMap;
};

#endif
