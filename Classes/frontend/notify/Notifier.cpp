//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "Notifier.h"
#include "BaseBehaviour.h"
Notifier* Notifier::instance = new Notifier();
Notifier::Notifier() { this->notifyMap = new std::map<int, INotify*>(); }
Notifier::~Notifier() { CC_SAFE_DELETE(this->notifyMap); }
Notifier* Notifier::getInstance() {
    if (NULL == Notifier::instance) {
        Notifier::instance = new Notifier();
    }
    return Notifier::instance;
}
void Notifier::destroy() {
    Notifier::getInstance()->clear();
    if (NULL != Notifier::instance) {
        CC_SAFE_DELETE(Notifier::instance);
    }
}
void Notifier::notify(NotifyMessage message) {
    for (std::map<int, INotify*>::iterator it = this->notifyMap->begin(); it != this->notifyMap->end(); it++) {
        INotify* notify = it->second;
        notify->onNotify(message);
    }
    this->previousMessage = this->currentMessage;
    this->currentMessage = message;
}
void Notifier::notify(int id, NotifyMessage message) {
    if (this->notifyMap->find(id) == this->notifyMap->end()) {
        return;
    }
    INotify* notify = this->notifyMap->at(id);
    notify->onNotify(message);
}
void Notifier::notify(NotifyMessage message, Parameter* parameter) {
    for (std::map<int, INotify*>::iterator it = this->notifyMap->begin(); it != this->notifyMap->end(); it++) {
        INotify* notify = it->second;
        notify->onNotify(message, parameter);
    }
    this->previousMessage = this->currentMessage;
    this->currentMessage = message;
}
void Notifier::notify(int id, NotifyMessage message, Parameter* parameter) {
    if (this->notifyMap->find(id) == this->notifyMap->end()) {
        return;
    }
    INotify* notify = this->notifyMap->at(id);
    notify->onNotify(message, parameter);
}
std::map<int, INotify*>* Notifier::getNotifyMap() { return this->notifyMap; }
void Notifier::add(INotify* notify, BaseProperty* property) {
    notify->id = property->getId();
    notify->type = property->getType();
    this->notifyMap->insert(std::map<int, INotify*>::value_type(notify->id, notify));
}
void Notifier::erase(int notifyId) {
    for (std::map<int, INotify*>::iterator it = this->notifyMap->begin(); it != this->notifyMap->end(); it++) {
        INotify* tmp = it->second;
        if (0 != tmp->type.length() && "layer" != tmp->type && notifyId == tmp->id) {
            it = this->notifyMap->erase(it);
            break;
        }
    }
}
void Notifier::clear() { this->notifyMap->clear(); }
