//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef Notifier_h
#define Notifier_h
#include <map>
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"
#include "BaseProperty.h"
class Notifier {
   public:
    static Notifier* getInstance();
    static void destroy();
    void notify(NotifyMessage message);
    void notify(NotifyMessage message, Parameter* parameter);
    void notify(int id, NotifyMessage message);
    void notify(int id, NotifyMessage message, Parameter* parameter);
    void add(INotify* notify, BaseProperty* property);
    void erase(int notifyId);
    void clear();
    std::map<int, INotify*>* getNotifyMap();
   private:
    NotifyMessage previousMessage;
    NotifyMessage currentMessage;
    std::map<int, INotify*>* notifyMap;
    static Notifier* instance;
    Notifier();
    ~Notifier();
};
#endif
