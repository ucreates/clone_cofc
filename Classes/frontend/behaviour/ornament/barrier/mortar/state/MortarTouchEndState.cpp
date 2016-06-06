//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "MortarTouchEndState.h"

// geography
#include "GeographicGateway.h"
#include "GeographicNode.h"
#include "GeographicDepth.h"
#include "BarrierBehaviourType.h"

// notify
#include "Notifier.h"
#include "NotifyMessage.h"

// utility
#include "Degree.h"
#include "Figure.h"
#include "Vector2D.h"
#include "Random.h"
#include "Alpha.h"

using namespace cocos2d;

MortarTouchEndState::MortarTouchEndState() {}

MortarTouchEndState::~MortarTouchEndState() {}

void MortarTouchEndState::create(Parameter* parameter) {
    Vec2 pos = parameter->get<Vec2>("touchPosition");
    GeographicGateway* gateway = GeographicGateway::getInstance();
    GeographicNode* node = gateway->findByPosition(pos);
    if (NULL == node || BarrierBehaviourType::None != node->type) {
        return;
    }

    std::vector<GeographicNode*> nodeVector = gateway->find2x2ByAddress(node->address);
    for (std::vector<GeographicNode*>::iterator it = nodeVector.begin(); it != nodeVector.end(); it++) {
        GeographicNode* areaNode = (*it);
        if (NULL == areaNode || BarrierBehaviourType::None != areaNode->type) {
            return;
        }
    }

    pos = node->position;
    this->owner->setGeographicNode(node);
    this->owner->setGeographicNodeVector(nodeVector);
    Parameter notifyParam;
    std::vector<int> idVector;
    for (std::vector<GeographicNode*>::iterator it = nodeVector.begin(); it != nodeVector.end(); it++) {
        GeographicNode* areaNode = (*it);
        areaNode->parentGeographicId = node->geographicId;
        if (areaNode->geographicId == node->geographicId) {
            areaNode->type = BarrierBehaviourType::Mortar;
        } else {
            areaNode->type = BarrierBehaviourType::Mortar + BarrierBehaviourType::AroundArea;
        }
        idVector.push_back(areaNode->geographicId);
    }
    notifyParam.set<std::vector<int>>("parameter", idVector);
    Notifier::getInstance()->notify(NotifyMessage::Route_Search_Test_Viewer_Node);
    Notifier::getInstance()->notify(NotifyMessage::Route_Search_Test_Viewer_Start, &notifyParam);

    GLubyte alpha = Alpha::NOT_ALPHA;

    AnimatorAsset* anime = (AnimatorAsset*)this->owner->getAsset("anime");
    anime->transform(pos, (OrnamentProperty*)this->owner->getProperty());
    anime->transform(node->depth + GeographicDepth::ORNAMENT_TOUCH_DEPTH);
    anime->transform(alpha);

    Notifier::getInstance()->notify(NotifyMessage::Geography_Editor_Reset);
    return;
}
