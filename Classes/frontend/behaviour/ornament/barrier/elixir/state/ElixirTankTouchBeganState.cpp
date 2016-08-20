//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "ElixirTankTouchBeganState.h"
// geography
#include "GeographicGateway.h"
#include "GeographicNode.h"
#include "GeographicDepth.h"
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
ElixirTankTouchBeganState::ElixirTankTouchBeganState() {}
ElixirTankTouchBeganState::~ElixirTankTouchBeganState() {}
void ElixirTankTouchBeganState::create(Parameter* parameter) {
    Vec2 pos = parameter->get<Vec2>("touchPosition");
    bool reset = parameter->get<bool>("reset");
    GeographicGateway* gateway = GeographicGateway::getInstance();
    GeographicNode* node = NULL;
    if (false != reset) {
        node = this->owner->getGeographicNode();
    } else {
        node = gateway->findByPosition(pos);
    }
    this->owner->clearGeographicNodeVector();
    if (NULL != node) {
        pos = node->position;
        std::vector<GeographicNode*> nodeVector = gateway->find4x4ByAddress(node->address);
        Parameter parameter;
        std::vector<int> idVector;
        for (std::vector<GeographicNode*>::iterator it = nodeVector.begin(); it != nodeVector.end(); it++) {
            GeographicNode* areaNode = (*it);
            idVector.push_back(areaNode->geographicId);
        }
        // asset
        GLubyte alpha = Alpha::HALF_ALPHA;
        AnimatorAsset* anime = (AnimatorAsset*)this->owner->getAsset("anime");
        anime->transform(pos, (OrnamentProperty*)this->owner->getProperty());
        anime->transform(GeographicDepth::ORNAMENT_TOUCH_DEPTH);
        anime->transform(alpha);
        parameter.set<std::vector<int>>("parameter", idVector);
        Notifier::getInstance()->notify(NotifyMessage::Route_Search_Test_Viewer_Node);
        Notifier::getInstance()->notify(NotifyMessage::Route_Search_Test_Viewer_Start, &parameter);
    }
    return;
}
