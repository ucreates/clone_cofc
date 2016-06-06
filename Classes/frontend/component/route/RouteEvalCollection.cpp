//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "RouteEvalCollection.h"

// notify
#include "Notifier.h"
#include "NotifyMessage.h"
#include "Value.h"
#include "Parameter.h"

RouteEvalCollection::RouteEvalCollection() { this->nodeVector = new std::vector<GeographicNode*>(); }

RouteEvalCollection::~RouteEvalCollection() { CC_SAFE_DELETE(this->nodeVector); }

void RouteEvalCollection::save(GeographicNode* node) { this->nodeVector->push_back(node); }

bool RouteEvalCollection::isEmpty() { return this->nodeVector->empty(); }

bool RouteEvalCollection::isEvaluatedNode(GeographicNode* evalNode) {
    for (std::vector<GeographicNode*>::iterator it = this->nodeVector->begin(); it != this->nodeVector->end(); it++) {
        GeographicNode* node = (GeographicNode*)(*it);
        if (node->address == evalNode->address) {
            return true;
        }
    }
    return false;
}

bool RouteEvalCollection::erase(GeographicNode* evalNode) {
    for (std::vector<GeographicNode*>::iterator it = this->nodeVector->begin(); it != this->nodeVector->end(); it++) {
        GeographicNode* node = (GeographicNode*)(*it);
        if (node->address == evalNode->address) {
            this->nodeVector->erase(it);
            return true;
        }
    }
    return false;
}

void RouteEvalCollection::clear() { this->nodeVector->clear(); }

std::vector<GeographicNode*>* RouteEvalCollection::getNodeVector() { return this->nodeVector; }

void RouteEvalCollection::dump() {
    Parameter parameter;
    std::vector<int> behaviourIdVector;
    for (std::vector<GeographicNode*>::iterator it = this->nodeVector->begin(); it != this->nodeVector->end(); it++) {
        GeographicNode* node = (GeographicNode*)(*it);
        behaviourIdVector.push_back(node->geographicId);
    }
    parameter.set<std::vector<int>>("parameter", behaviourIdVector);
    Notifier::getInstance()->notify(NotifyMessage::Route_Search_Test_Viewer_Node, &parameter);
}

RouteEvalCollection* RouteEvalCollection::operator=(RouteEvalCollection* value) {
    std::vector<GeographicNode*>::iterator it = value->getNodeVector()->begin();
    while (it != value->getNodeVector()->end()) {
        this->nodeVector->push_back((GeographicNode*)(*it));
        it++;
    }
    return this;
}
