//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef Response_h
#define Response_h

// stl
#include <map>
#include <string>

// cocos2d
#include "cocos2d.h"

#include "ServiceStatus.h"

// entity
#include "Value.h"

class Response {
   public:
    inline Response() {
        this->status = ServiceStatus::SUCCESS;
        this->responseMap = new std::map<std::string, BaseValue*>();
    }

    inline ~Response() {}

    template <typename T>
    inline T get(std::string name) {
        if (this->responseMap->find(name) != this->responseMap->end()) {
            std::map<std::string, BaseValue*>::iterator it = this->responseMap->find(name);
            Value<T>* element = (Value<T>*)(*it).second;
            T t = element->getValue();
            delete element;
            this->responseMap->erase(it);
            return t;
        }
        T t;
        return t;
    }

    template <typename T>
    inline void set(std::string name, T parameter) {
        if (this->responseMap->find(name) == this->responseMap->end()) {
            Value<T>* element = new Value<T>();
            element->setValue(parameter);
            this->responseMap->insert(std::map<std::string, BaseValue*>::value_type(name, element));
        }
    }

    inline void clear() {
        for (std::map<std::string, BaseValue*>::iterator it = this->responseMap->begin(); it != this->responseMap->end(); it++) {
            delete it->second;
        }
        CC_SAFE_DELETE(this->responseMap);
    }

    inline ServiceStatus getStatus() { return this->status; }

    inline void setStatus(ServiceStatus status) { this->status = status; }

   private:
    ServiceStatus status;
    std::map<std::string, BaseValue*>* responseMap;
};

#endif
