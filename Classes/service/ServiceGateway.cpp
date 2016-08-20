//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// stl
#include <regex>
// service
#include "ServiceGateway.h"
// utility
#include "StringUtility.h"
#include "BattleService.h"
#include "UnitService.h"
#include "BarrierService.h"
#include "ResourceService.h"
#include "MasterService.h"
#include "LoadingService.h"
#include "LogoService.h"
ServiceGateway* ServiceGateway::instance = NULL;
ServiceGateway::ServiceGateway() {
    this->add("battle", new BattleService());
    this->add("unit", new UnitService());
    this->add("barrier", new BarrierService());
    this->add("resource", new ResourceService());
    this->add("loading", new LoadingService());
    this->add("logo", new LogoService());
    this->add("master", new MasterService());
}
ServiceGateway::~ServiceGateway() {
    for (std::map<std::string, BaseService*>::iterator it = this->serviceMap.begin(); it != this->serviceMap.end(); it++) {
        CC_SAFE_DELETE(it->second);
    }
    this->clear();
}
ServiceGateway* ServiceGateway::getInstance() {
    if (NULL == ServiceGateway::instance) {
        ServiceGateway::instance = new ServiceGateway();
    }
    return ServiceGateway::instance;
}
BaseStrategy* ServiceGateway::request(std::string domainName) {
    std::string protocol = "service://";
    std::regex pattern(protocol);
    std::smatch ret;
    if (false == regex_search(domainName, ret, pattern)) {
        return NULL;
    }
    domainName.replace(0, protocol.length(), "");
    std::vector<std::string> schemaInfoVector = StringUtility::split(domainName, "/");
    if (0 == schemaInfoVector.size()) {
        return NULL;
    }
    std::string serviceName = schemaInfoVector.at(0);
    if (this->serviceMap.find(serviceName) == this->serviceMap.end()) {
        return NULL;
    }
    BaseService* service = this->serviceMap[serviceName];
    std::string strategyName = "";
    for (int i = 1; i < schemaInfoVector.size(); i++) {
        strategyName += schemaInfoVector.at(i);
        if (i < schemaInfoVector.size() - 1) {
            strategyName += "/";
        }
    }
    return service->create(strategyName);
}
bool ServiceGateway::add(std::string serviceName, BaseService* service) {
    if (this->serviceMap.find(serviceName) != this->serviceMap.end()) {
        return false;
    }
    this->serviceMap.insert(std::map<std::string, BaseService*>::value_type(serviceName, service));
    return true;
}
void ServiceGateway::clear() { this->serviceMap.clear(); }
void ServiceGateway::destroy() { CC_SAFE_DELETE(ServiceGateway::instance); }
