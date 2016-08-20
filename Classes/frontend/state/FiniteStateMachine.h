//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef FiniteStateMachine_h
#define FiniteStateMachine_h
#include <map>
#include "FiniteState.h"
#include "FiniteStateEntity.h"
#include "Parameter.h"
template <class T>
class FiniteStateMachine {
   public:
    inline FiniteStateMachine(T* owner) {
        this->finiteStateEntity = new FiniteStateEntity<T>();
        this->notifyParamter = new Parameter();
        this->owner = owner;
        this->hasParameter = false;
    }
    inline ~FiniteStateMachine() {
        for (typename std::map<std::string, FiniteState<T>*>::iterator it = this->stateList.begin(); it != this->stateList.end(); ++it) {
            CC_SAFE_DELETE(it->second);
        }
        for (typename std::map<std::string, FiniteState<T>*>::iterator it = this->persistenceStateList.begin(); it != this->persistenceStateList.end(); ++it) {
            CC_SAFE_DELETE(it->second);
        }
        CC_SAFE_DELETE(this->finiteStateEntity);
        CC_SAFE_DELETE(this->notifyParamter);
    }
    inline void change(std::string newStateName) { this->change(newStateName, NULL, false); }
    inline void change(std::string newStateName, bool update) { this->change(newStateName, NULL, update); }
    inline void change(std::string newStateName, Parameter* parameter, bool update = false) {
        if (NULL != parameter) {
            this->notifyParamter->copy(parameter);
            this->hasParameter = true;
        } else {
            this->hasParameter = false;
        }
        FiniteState<T>* nextState = this->get(newStateName);
        this->finiteStateEntity->update(newStateName, nextState);
        if (false != update) {
            this->update();
        }
    }
    inline void update(float delta = 0.0f) {
        if (this->finiteStateEntity->isNewState) {
            if (false != this->hasParameter) {
                if (false == this->finiteStateEntity->state->complete) {
                    this->finiteStateEntity->state->create(this->notifyParamter);
                }
            } else {
                if (false == this->finiteStateEntity->state->complete) {
                    this->finiteStateEntity->state->create();
                }
            }
            this->finiteStateEntity->isNewState = false;
        }
        if (NULL != this->finiteStateEntity->state && false == this->finiteStateEntity->state->complete && false == this->finiteStateEntity->state->wait) {
            this->finiteStateEntity->state->update(delta);
        }
        for (typename std::map<std::string, FiniteState<T>*>::iterator it = this->persistenceStateList.begin(); it != this->persistenceStateList.end(); it++) {
            if (false == it->second->complete) {
                it->second->update(delta);
            }
        }
    }
    inline FiniteState<T>* get(std::string stateName) {
        if (NULL != this->stateList[stateName]) {
            return this->stateList[stateName];
        }
        return NULL;
    }
    inline bool add(std::string stateName, FiniteState<T>* state, bool isFirstState = false) {
        if (false == state->persistence) {
            if (NULL == this->stateList[stateName]) {
                state->setOwner(this->owner);
                this->stateList[stateName] = state;
                return true;
            }
        } else {
            if (NULL == this->persistenceStateList[stateName]) {
                state->setOwner(this->owner);
                this->persistenceStateList[stateName] = state;
                return true;
            }
        }
        return false;
    }
    inline void play() {
        typename std::map<std::string, FiniteState<T>*>::iterator itr = this->stateList.begin();
        while (itr != this->stateList.end()) {
            FiniteState<T>* state = (FiniteState<T>*)itr->second;
            state->wait = false;
            state->complete = false;
            ++itr;
        }
        itr = this->persistenceStateList.begin();
        while (itr != this->persistenceStateList.end()) {
            FiniteState<T>* state = (FiniteState<T>*)itr->second;
            state->wait = false;
            state->complete = false;
            state->create();
            ++itr;
        }
    }
    inline void pause() {
        if (NULL != this->finiteStateEntity->state && false == this->finiteStateEntity->state->complete && false == this->finiteStateEntity->state->wait) {
            this->finiteStateEntity->state->wait = true;
        }
    }
    inline void stop() {
        typename std::map<std::string, FiniteState<T>*>::iterator itr = this->stateList.begin();
        while (itr != this->stateList.end()) {
            FiniteState<T>* state = (FiniteState<T>*)itr->second;
            state->complete = true;
            ++itr;
        }
        itr = this->persistenceStateList.begin();
        while (itr != this->persistenceStateList.end()) {
            FiniteState<T>* state = (FiniteState<T>*)itr->second;
            state->complete = true;
            ++itr;
        }
    }
    inline FiniteStateEntity<T>* getFiniteStateEntity() { return this->finiteStateEntity; }
   private:
    std::map<std::string, FiniteState<T>*> stateList;
    std::map<std::string, FiniteState<T>*> persistenceStateList;
    FiniteStateEntity<T>* finiteStateEntity;
    Parameter* notifyParamter;
    bool hasParameter;
    T* owner;
};
#endif
